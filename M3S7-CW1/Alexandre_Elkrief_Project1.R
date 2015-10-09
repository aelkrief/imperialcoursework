
#Question 1
#Q1b
tvals<-seq(0,4,by=0.1)

s1<-rep(0,length(tvals))
s2<-rep(0,length(tvals))
s3<-rep(0,length(tvals))
for (i in 1:length(tvals)){
  s1[i]<-0.5*(1-exp(-(tvals[i]^2)/32)+exp(-(tvals[i]^2)/(2*0.5^2)))
  s2[i]<-0.5*(1-exp(-(tvals[i]^2)/32)+exp(-(tvals[i]^2)/(2*1^2)))
  s3[i]<-0.5*(1-exp(-(tvals[i]^2)/32)+exp(-(tvals[i]^2)/(2*1.5^2)))
}
sigma<-c(0.5,1,1.5)

#plot Q1b error rate  
plot(tvals,s1,type="l",xlab = "T-Values",ylab = "Error")
lines(tvals,s2,type="l",col="red")
lines(tvals,s3,type="l",col="green")
legend("topright",legend=sigma,col=c("black","red","green"),lty=1,bty='n')


#Q1d
#Tmin for sigma=4& 1
Q1d<-2*4*1*(log(4/1)/(4^2-1^2))^0.5
Q1d
#Bayes error rate
eb<-0.5*(1-exp(-(Q1d^2)/32)+exp(-(Q1d^2)/(2*1^2)))
eb
#Q1e cost allocation new threshold
Q1e<-4*1*(2*log(5*(16/1))/(4^2-1^2))^0.5
Q1e

#Q1d-prior distribution
tvals<-seq(0,10,by=0.1)
f1<-rep(0,length(tvals))
f2<-rep(0,length(tvals))
for (i in 1:length(tvals)){
  f1[i]<-0.5*(tvals[i]/4^2)*exp(-tvals[i]^2/(2*4^2))
  f2[i]<-0.5*(tvals[i]/1^2)*exp(-tvals[i]^2/(2*1^2))
}
plot(tvals,f2,type="l",xlab="",ylab="",main="Prior Class Conditional Densities", col="blue")
lines(tvals,f1,type="l",col="red")
abline(v=Q1d,lty="dotted")
abline(v=Q1e)
legend("topright",legend=c("f(x|C1)","f(x|C2)"),col=c("red","blue"),lty=1,bty='n')


#Posterior distribution
tvals<-seq(0,10,by=0.1)
post1<-rep(0,length(tvals))
post2<-rep(0,length(tvals))
for (i in 1:length(tvals)){
  post1[i]<-(tvals[i]/4^2)*exp(-tvals[i]^2/(2*4^2))/((tvals[i]/4^2)*exp(-tvals[i]^2/(2*4^2))+(tvals[i]/1^2)*exp(-tvals[i]^2/(2*1^2)))
  post2[i]<-(tvals[i]/1^2)*exp(-tvals[i]^2/(2*1^2))/((tvals[i]/4^2)*exp(-tvals[i]^2/(2*4^2))+(tvals[i]/1^2)*exp(-tvals[i]^2/(2*1^2)))
  
}

plot(tvals,post1,type="l",xlab="",ylab="",ylim=c(0,1),col="red",main="Posterior Class Conditional Densities")
lines(tvals,post2,type="l",col="blue")
abline(v=Q1d,lty="dotted")
abline(v=Q1e,)
legend("topright",legend=c("p(C1|x)","p(C2|x)"),col=c("red","blue"),lty=1,bty='n')

#Question 2
#Q2a
#Random choice of x*
xstar <- runif(2,-6,6)
mu1 <- c(-1,-1)
mu2 <- c(1,1)
cov1<-matrix(c(1,0.2,0.2,1),nrow=2,ncol=2)
covinv1<-solve(cov1)
cov2<-matrix(c(1,-0.7,-0.7,1),nrow=2,ncol=2)
covinv2<-solve(cov2)

#Discriminant Function
discr<- function(x, mu1 = c(-1, -1), mu2 = c(1, 1))
{
  W1<-(-0.5)*covinv1
  W2<-(-0.5)*covinv2
  
  w1<-covinv1%*%mu1
  w2<-covinv2%*%mu2
  
  w10<-(-0.5)*t(mu1)%*%covinv1%*%mu1-0.5*log(abs(det(cov1)))+log(0.5)
  w20<-(-0.5)*t(mu2)%*%covinv2%*%mu2-0.5*log(abs(det(cov2)))+log(0.5)
  
  g1<-t(x)%*%W1%*%x+t(w1)%*%x+w10
  g2<-t(x)%*%W2%*%x+t(w2)%*%x+w20
  g1-g2
}


l <- 200
x <- seq(-6,6,length=l)
y <- x
gr <- as.matrix(expand.grid(x,y))
score.diff <-apply(gr,1,discr)
par(pty="s")
#Contour Plot
contour(x,y,matrix(score.diff,l),main="g1(x)-g2(x)")
text(xstar[1],xstar[2],"x")
#Heat Plot
image(x,y,matrix(score.diff,l),xlab = "",ylab = "",main="g1(x)-g2(x)")
text(xstar[1],xstar[2],"x")

#Question 3
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


#Q3c

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
legend("topright", legend=c("LDA","QDA","Bayes Error"),col=c("red","blue","black"),lty=1,bty='n')

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
#Taking the average error of the 10 trials
average.bayes.error<-mean(bayes.emperror.qda)
average.bayes.error
#Adding the Bayes error on the plot
abline(h=average.bayes.error)

#Question 4
#defining the function for which we find the minimum
f<-function(x){
  f.x=exp(-x)*sin(x) + sinh(x)
  return(f.x)
  
}
#setting the limiting values
x1<--4
x3<-0
eps<-0.000000001
grbrack<-function(f,x1,x3,eps){
  ratio<-(1+sqrt(5))/2
  x2<-x1+(x3-x1)/ratio
  x2
  i=0
  
  while ((x3-x1)>eps){
    i=i+1   
    
    f.x1=f(x1)
    f.x2=f(x2)
    f.x3=f(x3)
    if (f.x2<f.x1 && f.x2<f.x3){
      x3<-x2
      x2<-x1+(x3-x1)/ratio
    }
    else{
      x1<-x2
      x2<-x1+(x3-x1)/ratio 
    }  
  }
  return(f.x2)
}
grbrack(f,x1,x3,eps)

