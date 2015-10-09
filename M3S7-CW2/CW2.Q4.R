#Q4

#training.sample
#Redefining my training and test sets of data
q4train.c1<-cbind(training.sample$rray.x1,training.sample$rray.y1)
q4train.c2<-cbind(training.sample$rray.x2,training.sample$rray.y2)
q4train<-rbind(q4train.c1,q4train.c2)
q4train.class<-c(training.sample$rrayc1.class,training.sample$rrayc2.class)

xx<-q4train[1,]
yy<-q4train[2,]



#knn.alloc(c(0.3,0,3),q4train,q4train.class,11)

"knn.dist"<-function(train,test,class,k){
  "dist"<-function(x,y){
    return(sqrt((x[1]-y[1])^2+(x[2]-y[2])^2))
  }
  "dist.vector"<-function(x.star,datapoints){
    dist.vec<-rep(0,length(datapoints[,1]))
    for (i in 1:length(datapoints[,1])){
      dist.vec[i]<-dist(x.star,datapoints[i,])
    }
    return(dist.vec)
  }
  "tricube"<-function(x){
    y<-(1-abs(x)^3)^3
    return(y)
  }
  
  "knn.alloc"<-function(x.star,traindata,classvec,K){
    
    dist.vec<-dist.vector(x.star,traindata)
    scale.dist.vec<-dist.vec/max(dist.vec)
    
    knn.index<-order(scale.dist.vec)[1:K]
    knn.points<-matrix(0,nrow=K,ncol=6)
    
    for (i in 1:K){
      #first points of the knn.points is x.star
      knn.points[i,1]<-traindata[knn.index[i],1]
      knn.points[i,2]<-traindata[knn.index[i],2]
      knn.points[i,3]<-classvec[knn.index[i]]
      knn.points[i,4]<-scale.dist.vec[knn.index[i]]
      
      if (knn.points[i,3]==1){
        knn.points[i,5]<-tricube(knn.points[i,4])
      }
      else{
        knn.points[i,6]<-tricube(knn.points[i,4])
      }
    }
    #print(knn.points)
    weights.vec1<-knn.points[,5]
    weights.vec2<-knn.points[,6]
    #need to remove 1
    
    w1<-sum(weights.vec1)
    w2<-sum(weights.vec2)
    if (w1>w2){
      x.star.alloc<-1
    }
    else if (w1<w2){x.star.alloc<-2}
    else{x.start.alloc<-sample(1:2,1)}
    
    #   print(knn.points)
    #   print(weights.vec1)
    #   print(weights.vec2)
    return(x.star.alloc)
  }
  alloc<-apply(test,1,knn.alloc,traindata=train,classvec=class,K=k)
  return(alloc)  
}

#Q4b
kvec<-c(3,7,11,15,19,23,27,31,35,39)
#D1
#D2
#D1.true.c
#D2.true.c
"knn.cross.err"<-function(D1,D2,D1.class,D2.class,K){
  knn12<-knn.dist(D1,D2,D1.class,K)
  knn12.table<-table(D1.class,knn12)
  knn12.err<-(knn12.table[1,2]+knn12.table[2,1])/100
  
  knn21<-knn.dist(D2,D1,D2.class,K)
  knn21.table<-table(D2.class,knn21)
  knn21.err<-(knn21.table[1,2]+knn21.table[2,1])/100
  
  knn.average<-0.5*(knn12.err+knn21.err)
  return(knn.average)
}



"knn.k.opt"<-function(D1,D2,D1.class,D2.class,kvec){
  knn.err.vec<-rep(0,length(kvec))
  for (i in 1:length(kvec)){
    knn.err.vec[i]<-knn.cross.err(D1,D2,D1.true.c,D2.true.c,kvec[i])
  }
  
  z<-which.min(knn.err.vec)
  #print(knn.err.vec)
  #print(z)
  best<-kvec[z]
  return(best)
}

k.best<-knn.k.opt(D1,D2,D1.true.c,D2.true.c,kvec)
k.best
#Q4c
#Using the k.best found above
q4test.c1<-cbind(test.sample$rray.x1,test.sample$rray.y1)
q4test.c2<-cbind(test.sample$rray.x2,test.sample$rray.y2)
q4test<-rbind(q4test.c1,q4test.c2)
q4test.class<-c(test.sample$rrayc1.class,test.sample$rrayc2.class)

q4c<-knn.dist(q4train,q4test,q4train.class,k.best)
q4c.table<-table(q4test.class,aa)
q4c.error<-(q4c.table[1,2]+q4c.table[2,1])/sum(q4c.table)
q4c.error
