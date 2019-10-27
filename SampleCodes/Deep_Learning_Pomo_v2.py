import os,cv2
import numpy as np
import matplotlib.pyplot as plt
import matplotlib
from PIL import Image
from numpy import *

from sklearn.utils import shuffle
from sklearn.cross_validation import train_test_split

from keras import backend as K
K.set_image_dim_ordering('tf')

from keras.utils import np_utils
from keras.models import Sequential
from keras.layers.core import Dense, Dropout, Activation, Flatten
from keras.layers.convolutional import Convolution2D, MaxPooling2D
from keras.optimizers import SGD,RMSprop,adam


path1='D:\Pomo Disease dataset\Input'
path2='D:\Pomo Disease dataset\Input_resized'

listing = os.listdir(path1) 
num_samples=size(listing)
print (num_samples)

img_rows=128
img_cols=128
num_channel=1
num_epoch=20

for file in listing:
    im = Image.open(path1 + '\\' + file)   
    img = im.resize((img_rows,img_cols))
    gray = img.convert('L') #need to do some more processing here           
    gray.save(path2 +'\\' +  file, "JPEG")
    
imlist = os.listdir(path2)

im1 = array(Image.open('D:\Pomo Disease dataset\Input_resized' + '\\'+ imlist[0])) # open one image to get size
m,n = im1.shape[0:2] # get the size of the images
imnbr = len(imlist) # get the number of images

# create matrix to store all flattened images
 
immatrix = array([array(Image.open('D:\Pomo Disease dataset\Input_resized'+ '\\' + im2)).flatten()
              for im2 in imlist],'f')

label=np.ones((num_samples,),dtype = int)

label[0:20]=0
label[20:43]=1
label[43:49]=2
label[49:58]=3               
label[58:73]=4

data,Label = shuffle(immatrix,label, random_state=2)
train_data = [data,Label]

img=immatrix[4].reshape(img_rows,img_cols)
plt.imshow(img)
plt.imshow(img,cmap='gray')
print (train_data[0].shape)
print (train_data[1].shape)

#%%

#batch_size to train
batch_size = 30
# number of output classes
nb_classes = 5


nb_epoch=20
# number of convolutional filters to use
nb_filters = 32
# size of pooling area for max pooling
nb_pool = 2
# convolution kernel size
nb_conv = 3

#%%
(X, y) = (train_data[0],train_data[1])

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=4)

X_train = X_train.reshape(X_train.shape[0], img_rows, img_cols,1)
X_test = X_test.reshape(X_test.shape[0], img_rows, img_cols,1)

X_train = X_train.astype('float32')
X_test = X_test.astype('float32')

X_train /= 255
X_test /= 255

print('X_train shape:', X_train.shape)
print(X_train.shape[0], 'train samples')
print(X_test.shape[0], 'test samples')

Y_train = np_utils.to_categorical(y_train, nb_classes)
Y_test = np_utils.to_categorical(y_test, nb_classes)

#%%
# Defining the model

					
model = Sequential()

model.add(Convolution2D(32, (3,3),border_mode='same',input_shape=(img_rows, img_cols,1))) #CHANGE IN CODE
convout1=Activation('relu')
model.add(convout1)
model.add(Convolution2D(32, (3, 3)))
convout2=Activation('relu')
model.add(convout2)
model.add(MaxPooling2D(pool_size=(2, 2)))
model.add(Dropout(0.5))

model.add(Convolution2D(64, (3, 3)))
convout3=Activation('relu')
model.add(convout3)
#model.add(Convolution2D(64, 3, 3))
#model.add(Activation('relu'))
model.add(MaxPooling2D(pool_size=(2, 2)))
model.add(Dropout(0.5))

model.add(Flatten())
model.add(Dense(64))
model.add(Activation('relu'))
model.add(Dropout(0.5))
model.add(Dense(nb_classes)) #CHANGE IN PARA
model.add(Activation('softmax'))

#sgd = SGD(lr=0.01, decay=1e-6, momentum=0.9, nesterov=True)
#model.compile(loss='categorical_crossentropy', optimizer=sgd,metrics=["accuracy"])
model.compile(loss='categorical_crossentropy', optimizer='rmsprop',metrics=["accuracy"])

#%%
hist = model.fit(X_train, Y_train, batch_size=16, nb_epoch=nb_epoch, verbose=1, validation_data=(X_test, Y_test))

score = model.evaluate(X_test, Y_test,verbose=0)
print('Test score:', score[0])
print('Test accuracy:', score[1])

print(model.predict_classes(X_test[1:6]))
print(Y_test[1:6])


# Viewing model_configuration

model.summary()
model.get_config()
model.layers[0].get_config()
model.layers[0].input_shape			
model.layers[0].output_shape			
model.layers[0].get_weights()
np.shape(model.layers[0].get_weights()[0])
model.layers[0].trainable

# visualizing losses and accuracy
train_loss=hist.history['loss']
val_loss=hist.history['val_loss']
train_acc=hist.history['acc']
val_acc=hist.history['val_acc']
xc=range(num_epoch)

plt.figure(1,figsize=(7,5))
plt.plot(xc,train_loss)
plt.plot(xc,val_loss)
plt.xlabel('num of Epochs')
plt.ylabel('loss')
plt.title('train_loss vs val_loss')
plt.grid(True)
plt.legend(['train','val'])
#print plt.style.available # use bmh, classic,ggplot for big pictures
plt.style.use(['classic'])

plt.figure(2,figsize=(7,5))
plt.plot(xc,train_acc)
plt.plot(xc,val_acc)
plt.xlabel('num of Epochs')
plt.ylabel('accuracy')
plt.title('train_acc vs val_acc')
plt.grid(True)
plt.legend(['train','val'],loc=4)
#print plt.style.available # use bmh, classic,ggplot for big pictures
plt.style.use(['classic'])

#%%
from sklearn.metrics import classification_report,confusion_matrix

Y_pred = model.predict(X_test)
print(Y_pred)
y_pred = np.argmax(Y_pred, axis=1)
print(y_pred)
   #or
y_pred = model.predict_classes(X_test)
print(y_pred)

#%%
#plotting probability
p=model.predict_proba(X_test) # to predict probability
print(p)
   
#%%
target_names = ['class 0(Alternaria Alternata)', 'class 1(Anthracnose)', 'class 2(Bacterial Blight)','class 3(Cercospora Leaf Spot)','class 4(Healthy Leaves-12.jpg)']
print(classification_report(np.argmax(Y_test,axis=1), y_pred,target_names=target_names))
print(confusion_matrix(np.argmax(Y_test,axis=1), y_pred))

#%%
# saving weights

fname = "weights-Test-CNN.hdf5"
model.save_weights(fname,overwrite=True)
#%%
fname = "weights-Test-CNN.hdf5"
model.load_weights(fname)


