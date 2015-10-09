mu1 <- c(-1,-1)
mu2 <- c(1,1)
sigma <- matrix(c(0.5,0.2,0.2,0.5),ncol=2)
sigma
n <- 30
d1 <- rmvnorm(n,mu1,sigma)
d2 <- rmvnorm(n,mu2,sigma)
d1
# w <- rnorm(3,0,1)
w <- c(-0.792, 0.793, -0.892)

aug.dat <-  rbind(cbind(1,d1),  cbind(-1,- d2))
aug.dat
y <- aug.dat %*% w
indx <- y < 0
percep <- -sum(aug.dat[indx,]%*%w)

par(pty='s')
plot(rbind(d1,d2),type="n")
points(d1[,1],d1[,2],pch=1,col=1)
points(d2[,1],d2[,2],pch=2,col=2)

#Q7
set.seed(1)
w <- rnorm(2,0,1)
d1y <- d1%*%w
d2y <- d2%*%w
xlim <- c(-4,4)
par(mfrow=c(1,2))
hist(d1y,xlim=xlim)
hist(d2y,xlim=xlim)
within <- (mean(d1y)-mean(d2y))^2
between <- var(d1y)+var(d2y)
within/between

