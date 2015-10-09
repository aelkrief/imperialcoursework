#Q1a
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


#Posterior distribution
tvals<-seq(0,10,by=0.1)
post1<-rep(0,length(tvals))
post2<-rep(0,length(tvals))
for (i in 1:length(tvals)){
  post1[i]<-(tvals[i]/4^2)*exp(-tvals[i]^2/(2*4^2))/((tvals[i]/4^2)*exp(-tvals[i]^2/(2*4^2))+(tvals[i]/1^2)*exp(-tvals[i]^2/(2*1^2)))
  post2[i]<-(tvals[i]/1^2)*exp(-tvals[i]^2/(2*1^2))/((tvals[i]/4^2)*exp(-tvals[i]^2/(2*4^2))+(tvals[i]/1^2)*exp(-tvals[i]^2/(2*1^2)))

}

plot(tvals,post1,type="l",xlab="",ylab="",ylim=c(0,1),col="blue",main="Posterior Class Conditional Densities")
lines(tvals,post2,type="l",col="red")
abline(v=Q1d,lty="dotted")
abline(v=Q1e,)

