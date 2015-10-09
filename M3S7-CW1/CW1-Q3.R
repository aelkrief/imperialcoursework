#Q3a-b
p<-floor(runif(1,0,6))+10

mu1<-rep(0,p)
mu2<-runif(p)

cov1<-diag(p)
cov2<-0.5*diag(p)
cov2[1,3]<--0.3
cov2[3,1]<--0.3
cov2[2,3]<-0.2
cov2[3,2]<-0.2
cov2[4,8]<-0.1
cov2[8,4]<-0.1
cov2

#Q1c

emperror.lda<-rep(0,10)
emperror.qda<-rep(0,10)


for (i in 1:10){
  trainC1<-mvrnorm(0.25*i*100,mu1,cov1)
  trainC2<-mvrnorm(0.75*i*100,mu2,cov2)
  traindata<-rbind(trainC1,trainC2)

  trainclassC1<-rep(1,0.25*i*100)
  trainclassC2<-rep(2,0.75*i*100)
  trainclass<-c(trainclassC1,trainclassC2)


  testC1<-mvrnorm(1000,mu1,cov1)
  testC2<-mvrnorm(3000,mu2,cov2)
  testdata<-rbind(testC1,testC2)

  testclassC1<-rep(1,1000)
  testclassC2<-rep(2,3000)
  testclass<-c(testclassC1,testclassC2)
 

#qda
  train.qda<-qda(traindata,trainclass)
  prediction.qda<-predict(train.qda,testdata)
  table.qda<-table(prediction.qda$class,testclass)
  emperror.qda[i]<-(table.qda[1,2]+table.qda[2,1])/4000
  
#lda
  train.lda<-lda(traindata,trainclass)
  prediction.lda<-predict(train.lda,testdata)
  table.lda<-table(prediction.lda$class,testclass)
  emperror.lda[i]<-(table.lda[1,2]+table.lda[2,1])/4000
}
emperror.lda
emperror.qda


#Q3d
plot(seq(100,1000,100),emperror.qda,type="l",xlab = "Training Set Size",ylab = "Out of Sample Error",col="blue",ylim=c(0.02,max(emperror.qda)+0.03))
lines(seq(100,1000,100),emperror.lda,col="red")
legend("topright", legend=c("LDA","QDA"),col=c("red","blue"),lty=1,bty='n')

#Q3f

bayes.emperror.qda<-rep(0,10)

for (i in 1:10){
  trainC1<-mvrnorm(0.25*15000,mu1,cov1)
  trainC2<-mvrnorm(0.75*15000,mu2,cov2)
  traindata<-rbind(trainC1,trainC2)
  
  trainclassC1<-rep(1,0.25*15000)
  trainclassC2<-rep(2,0.75*15000)
  trainclass<-c(trainclassC1,trainclassC2)
  
  
  testC1<-mvrnorm(15000,mu1,cov1)
  testC2<-mvrnorm(45000,mu2,cov2)
  testdata<-rbind(testC1,testC2)
  
  testclassC1<-rep(1,15000)
  testclassC2<-rep(2,45000)
  testclass<-c(testclassC1,testclassC2)
  
  length(testclass)
  
  #qda
  train.qda<-qda(traindata,trainclass)
  prediction.qda<-predict(train.qda,testdata)
  table.qda<-table(prediction.qda$class,testclass)
  bayes.emperror.qda[i]<-(table.qda[1,2]+table.qda[2,1])/60000
}
bayes.emperror.qda
average.bayes.error<-mean(bayes.emperror.qda)
average.bayes.error
abline(h=average.bayes.error)


