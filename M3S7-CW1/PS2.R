jj1 <- matrix(runif(100),ncol=10)
rand.mat <- matrix(runif(500),ncol=10)
apply(rand.mat,2,quantile,p=0.75)

"twonormsa" <-function(n, p1, mu1 = 0, mu2)
  {
    n1 <- round(n * p1)
    n2 <- n - n1
    x1 <- rnorm(n1, mu1, 1)
    x2 <- rnorm(n2, mu2, 1)
    cl <- c(rep(0, length(n1)), rep(1, length(n2)))
    list(cl = cl, x= c(x1, x2))
  }

rocloop <- function(cl,x)
{
  TP <- rep(0,length(cl))
  FP <- rep(0,length(cl))
  numcl0 <- sum(cl == 0)
  numcl1 <- sum(cl == 1)
  xcl0 <- x[1:numcl0]
  xcl1 <- x[(numcl0+1):length(cl)]
  for(i in 1:length(cl))
  {
    TP[[i]] <- sum(xcl0<x[i])/numcl0
    FP[[i]] <- sum(xcl1<x[i])/numcl1
  }
  list(TP=c(TP,1),FP=c(FP,1))
}


# roc<-function(cl, x)
# {
#   yav <- rep(tapply(cl, x, mean), table(x))
#   rocx <- cumsum(yav)
#   rocy <- cumsum(1 - yav)
#   area <- sum(yav * (rocy - 0.5 * (1 - yav)))
#   list(FP = c(0, rocx)/sum(cl), TP = c(0, rocy)/sum(1 - cl), area =
#          area/(sum(cl) * sum(1 - cl)))
# }



avals <- c(0.2,seq(1,4.5,by=0.5))
par(mfrow=c(3,3),pty="s")
for (i in 1:length(avals)){
  jj1 <- twonormsa(1000,0.5,0,avals[i])
  ROC <- roc(jj1$cl,jj1$x) # or use rocloop.R
  plot(ROC$FP,ROC$TP,xlab="1-sensitivity",ylab="specificity")
  abline(0,1)
  legend(0.5,0.3,c(paste("a=",as.character(avals[i]))))
  }
xstar <- runif(2,-3,3)
mu1 <- c(1,0)
mu2 <- c(-1,0)
md1 <- sqrt(t(mu1 -xstar)%*%diag(1,2)%*%(mu1 -xstar))
md2 <- sqrt(t(mu2 -xstar)%*%diag(1,2)%*%(mu2 -xstar))

"discr1" <-
  function(x, mu1 = c(1, 0), mu2 = c(-1, 0))
  {
    ds1 <- t(mu1) %*% x - t(mu1) %*% mu1
    ds2 <- t(mu2) %*% x - t(mu2) %*% mu2
    ds1 - ds2
  }

l <- 20
x <- seq(-3,3,length=l)
y <- x
gr <- as.matrix(expand.grid(x,y))
score.diff <-apply(gr,1,discr1)
par(pty="s")
contour(x,y,matrix(score.diff,l))
text(xstar[1],xstar[2],"X")




