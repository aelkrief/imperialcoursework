#Q3

"kernel"<-function(z){
  return((1/sqrt(2*pi))*exp(-z^2/2))
}

"kde"<-function(x.star,data,bw){
  d<-length(x.star)
  n<-length(data[,1])
  h<-prod(bw)
  m<-matrix(rep(0,n*d),nrow=n,ncol=d)
  for (i in 1:n){
    for (j in 1:d){
      m[i,j]<-(x.star[j]-data[i,j])/bw[j]
    }
  }
  m2<-apply(m,1:2,kernel)
  vec<-m2[,1]*m2[,2]
  s<-sum(vec)
  p<-(1/(n*h))*s
  return(p)
}
#h<-c(0.2,0.5)
#x.star<-c(points$rray.x2[7],points$rray.y2[7])

dataset<-cbind(training.sample$rray.x1,training.sample$rray.y1)
dataset2<-cbind(training.sample$rray.x2,training.sample$rray.y2)
#kde(x.star,dataset,h)
#kde(x.star,dataset2,h)

#Q3b
#Dividing the training set in D1 and D2 randomly
dataset.c1<-cbind(training.sample$rray.x1,training.sample$rray.y1)
dataset.c2<-cbind(training.sample$rray.x2,training.sample$rray.y2)
d1.c1<-sample(1:100,50,replace=F)
d1.c2<-sample(1:100,50,replace=F)

d2.c1<-rep(0,100)
d2.c2<-rep(0,100)

for (i in 1:100){
  if (i %in% d1.c1==FALSE){
    d2.c1[i]<-i
  }
  if (i %in% d1.c2==FALSE){
    d2.c2[i]<-i
  }
}
d2.c1<-d2.c1[d2.c1!=0]
d2.c2<-d2.c2[d2.c2!=0]

cross1.c1<-matrix(0,nrow=50,ncol=2)
cross1.c2<-cross1.c1
cross2.c1<-cross1.c1
cross2.c2<-cross1.c1

for (i in 1:50){
  cross1.c1[i,]<-dataset.c1[d1.c1[i],]
  cross2.c1[i,]<-dataset.c1[d2.c1[i],]
  cross1.c2[i,]<-dataset.c2[d1.c2[i],]
  cross2.c2[i,]<-dataset.c2[d2.c2[i],]
}
D1<-rbind(cross1.c1,cross1.c2)
D1.true.c<-c(rep(1,50),rep(2,50))
D2<-rbind(cross2.c1,cross2.c2)
D2.true.c<-D1.true.c
H<-expand.grid(seq(0.05,1,0.05),seq(0.05,1,0.05))

x.starr<-D2[1,]

"crossval12"<-function(h){
  for (i in 1:100){
    T[i,1]<-kde(D2[i,],cross1.c1,h)
    T[i,2]<-kde(D2[i,],cross1.c2,h)
    if (T[i,1]>T[i,2]){
      T[i,3]<-1
    }
    else{
      T[i,3]<-2
    }  
  }
  tt<-table(T[,3],D2.true.c)
  error<-(tt[1,2]+tt[2,1])/length(T[,3])
  return(error)
}

"crossval21"<-function(h){
  for (i in 1:100){
    T[i,1]<-kde(D1[i,],cross2.c1,h)
    T[i,2]<-kde(D1[i,],cross2.c2,h)
    if (T[i,1]>T[i,2]){
      T[i,3]<-1
    }
    else{
      T[i,3]<-2
    }  
  }
  tt<-table(T[,3],D1.true.c)
  error<-(tt[1,2]+tt[2,1])/length(T[,3])
  return(error)
}

"error.class"<-function(h,testdata,traindata.c1,traindata.c2,true.class.vec){
  T<-matrix(0,nrow=length(testdata[,1]),ncol=3)
  for (i in 1:length(testdata[,1])){
    T[i,1]<-kde(testdata[i,],traindata.c1,h)
    T[i,2]<-kde(testdata[i,],traindata.c2,h)
    if (T[i,1]>T[i,2]){
      T[i,3]<-1
    }
    else{
      T[i,3]<-2
    }  
  }
  tt<-table(T[,3],true.class.vec)
  error<-(tt[1,2]+tt[2,1])/length(T[,3])
  return(error)
}

error.vec12<-rep(0,400)
error.vec21<-rep(0,400)
for (i in 1:400){
  h<-c(H[i,1],H[i,2])
  error.vec12[i]<-error.class(h,D2,cross1.c1,cross1.c2,D2.true.c)
  error.vec21[i]<-error.class(h,D1,cross2.c1,cross2.c2,D1.true.c)
}

# h<-c(H[1,1],H[1,2])
# min(error.vec12)
# min(error.vec21)
error.tot<-0.5*(error.vec12+error.vec21)
error.tot
min(error.tot)
b<-which.min(error.tot)
h.best<-c(H[b,1],H[b,2])
h.best

#Q3d
test.sample
datatrain.c1<-cbind(training.sample$rray.x1,training.sample$rray.y1)
datatrain.c2<-cbind(training.sample$rray.x2,training.sample$rray.y2)
datatest.c1<-cbind(test.sample$rray.x1,test.sample$rray.y1)
datatest.c2<-cbind(test.sample$rray.x2,test.sample$rray.y2)
datatest.tot<-rbind(datatest.c1,datatest.c2)
#datatest.tot
datatest.true.c<-c(test.sample$rrayc1.class,test.sample$rrayc2.class)


error.class(h.best,datatest.tot,datatrain.c1,datatrain.c2,datatest.true.c)
