
#Q2a
xstar <- runif(2,-6,6)
mu1 <- c(-1,-1)
mu2 <- c(1,1)
cov1<-matrix(c(1,0.2,0.2,1),nrow=2,ncol=2)
covinv1<-solve(cov1)
cov2<-matrix(c(1,-0.7,-0.7,1),nrow=2,ncol=2)
covinv2<-solve(cov2)

#discriminant
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
#   print(g1)
#   print(g2)
  g1-g2
}

xstar
discr(xstar)
discr
l <- 200
x <- seq(-6,6,length=l)
y <- x
gr <- as.matrix(expand.grid(x,y))
score.diff <-apply(gr,1,discr)
par(pty="s")
contour(x,y,matrix(score.diff,l),main="g1(x)-g2(x)")
text(xstar[1],xstar[2],"x")
image(x,y,matrix(score.diff,l),xlab = "",ylab = "",main="g1(x)-g2(x)")
text(xstar[1],xstar[2],"x")



                  
                        
