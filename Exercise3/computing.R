vec1<-NULL
vec2<-NULL
for (i in 1:20){
  vec1[i]<-(2^i)*log(2^i)/log(2) 
  vec2[i]<-(2^i)
}

f_star_cN2<-c(4,12,32,80,192,448,1024,2304,5120,11264,24576,53248,114688,245760,524288,1114112,2359296,4980736,10485760,22020096)

lm1<-lm(f_star_cN2~vec1+vec2-1)
summary(lm1)
plot(f_star_cN2,type='l')
points(predict(lm1),type='l',col='red')
lm1$coefficients

f_add_cN2<-c(2,8,24,64,160,384,896,2048,4608,10240,22528,49152,106496,229376,491520,1048576,2228224,4718592,9961472,20971520)
lm2<-lm(f_add_cN2~vec1+vec2-1)
lm2$coefficients
plot(f_add_cN2,type='l')
points(predict(lm2))

f_star_rN2<-c(16,48,128,320,  768,  1792,  4096,  9216,  20480,  45056,  98304,  212992,  458752,  983040,  2097152,  4456448,  9437184,  19922944,  41943040,  88080384)
lm3<-lm(f_star_rN2~vec1+vec2-1)
lm3$coefficients
plot(f_star_rN2,type='l')
points(predict(lm3))

f_add_rN2<-c(12,40,112,288,704,1664,3840,8704,19456,43008,94208,204800,442368,950272,2031616,4325376,9175040,19398656,40894464,85983232)
lm4<-lm(f_add_rN2~vec1+vec2-1)
lm4$coefficients
plot(f_add_rN2,type='l')
points(predict(lm4))

f_star_cN3<-c(9,22,52,120,272,608,1344,2944,6400,13824,29696,63488,135168,286720,606208,1277952,2686976,5636096,11796480,24641536)
lm5<-lm(f_star_cN3~vec1+vec2-1)
lm5$coefficients
plot(f_star_cN3,type='l')
points(predict(lm5))

f_add_cN3<-c(6,16,40,96,224,512,1152,2560,5632,12288,26624,57344,122880,262144,557056,1179648,2490368,5242880,11010048,23068672)
lm6<-lm(f_add_cN3~vec1+vec2-1)
lm6$coefficients
plot(f_add_cN3,type='l')
points(predict(lm6))

f_star_rN3<-c(36,60,136,304,672,1472,3200,6912,14848,31744,67584,143360,303104,638976,1343488,2818048,5898240,12320768,25690112,53477376)
lm7<-lm(f_star_rN3~vec1+vec2-1)
lm7$coefficients
plot(f_star_rN3,type='l')
points(predict(lm7))

f_add_rN3<-c(30,76,184,432,992,2240,4992,11008,24064,52224,112640,241664,516096,1097728,2326528,4915200,10354688,21757952,45613056,95420416)
lm8<-lm(f_add_rN3~vec1+vec2-1)
lm8$coefficients
plot(f_add_rN3,type='l')
points(predict(lm8))




