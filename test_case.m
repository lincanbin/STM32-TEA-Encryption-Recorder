[X,FS,NBITS]=wavread('F:\Backup\REC00002.wav');
t=(0:length(X)-1)/FS;
subplot(2,2,1);plot(t,X);