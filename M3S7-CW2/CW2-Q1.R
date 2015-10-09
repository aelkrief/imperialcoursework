#Q1
install.packages("mvtnorm")
install.packages("plotrix")
library("MASS")
library("mvtnorm")
#(a)


em.norm<-function(x,means,covariances,mix.prop){
  "loglike"<-function(datapoints,pi,mu,sigma){
    takelog<-rep(0,k)
    log.like.inter<-rep(0,n)
    for (i in 1:n){
      for (j in 1:k){
        takelog[j]<-pi[j]*dmvnorm(datapoints[i,],mu[[j]],sigma[[j]])      
      }
      log.like.inter[i]<-log(sum(takelog))
    }
    log.like<-sum(log.like.inter)
    return(log.like)
  }
  
  old.pii<-mix.prop
  old.mui<-means
  old.covi<-covariances
  n<-length(x[,1])
  k=length(old.pii)
  old.log.like<-loglike(x,old.pii,old.mui,old.covi)
  gam.nom<-matrix(0,nrow=n,ncol=k)
  new.mui<-list(0)[rep(1,k)]
  new.pii<-rep(0,k)
  new.covi<-list(0)[rep(1,k)]
  inter.mat<-list(0)[rep(1,n)]
  new.log.like<-0
  z<-0
  
  while (z<=100 & abs(old.log.like-new.log.like)>0.1){  
    old.log.like<-new.log.like
    for (j in 1:n){
      for (kk in 1:k){
        gam.nom[j,kk]<-old.pii[kk]*dmvnorm(x[j,],old.mui[[kk]],old.covi[[kk]]) 
      }
    }
    #gam.nom
    gam.denom<-1/apply(gam.nom,1,sum)
    #gam.denom
    gamma<-gam.nom*gam.denom

    nvec<-apply(gamma,2,sum)

    for (i in 1:k){
      new.mui[[i]]<-(1/nvec[i])*apply(gamma[,i]*x,2,sum)
      new.pii[i]<-nvec[i]/n
    }
    new.mui
    new.pii
    
    for (i in 1:k){
      for (j in 1:n){
        inter.mat[[j]]<-gamma[j,i]*(x[j,]-new.mui[[i]])%*%t(x[j,]-new.mui[[i]])
      }
      new.covi[[i]]<-Reduce("+",inter.mat)*(1/nvec[i])
    }

    new.log.like<-loglike(x,new.pii,new.mui,new.covi)
    print(new.log.like)
    
    old.pii<-new.pii
    old.mui<-new.mui
    old.covi<-new.covi
    z<-z+1
  }
  result<-list(means=new.mui,covariances=new.covi,mix.prop=new.pii,ML.est=new.log.like,iterations=z)
  return(result)
}

x<-as.matrix(synth.te[,-3])
#Initial covariances chose randomly
cov1<-matrix(c(1,0.6,0.6,1),nrow=2,ncol=2)
cov2<-matrix(c(1.5,0.7,0.7,1.5),nrow=2,ncol=2)
cov3<-matrix(c(2.8,1.2,1.2,2.8),nrow=2,ncol=2)
cov4<-matrix(c(0.8,0.2,0.2,0.8),nrow=2,ncol=2)
cov5<-matrix(c(1.3,0.4,0.4,1.3),nrow=2,ncol=2)
cov6<-matrix(c(3.1,0,0,3.1),nrow=2,ncol=2)

#K=2
old.pii2<-c(7/10,3/10)
old.mui2<-list(c(1,1.3),c(3,2))
old.covi2<-list(cov1,cov2)
k2<-list(old.mui2,old.covi2,old.pii2)
#K=3
old.pii3<-c(4/10,3/10,3/10)
old.mui3<-list(c(1,1.3),c(1,4),c(3,0))
old.covi3<-list(cov1,cov2,cov3)
k3<-list(old.mui3,old.covi3,old.pii3)
#K=4
old.pii4<-c(3/10,2/10,1/10,4/10)
old.mui4<-list(c(1,1.3),c(1,4),c(3,0),c(2.5,1.3))
old.covi4<-list(cov1,cov2,cov3,cov4)
k4<-list(old.mui4,old.covi4,old.pii4)
#K=5
old.pii5<-c(2/10,3/10,1/10,2/10,2/10)
old.mui5<-list(c(1,1.3),c(1,4),c(3,0),c(2.5,1.3),c(0.2,0.2))
old.covi5<-list(cov1,cov2,cov3,cov4,cov5)
k5<-list(old.mui5,old.covi5,old.pii5)
#K=6
old.pii6<-c(9/100,12/100,27/100,18/100,12/100,22/100)
old.mui6<-list(c(1,1.3),c(1,4),c(3,0),c(2.5,1.3),c(0.2,0.2),c(0.4,1.6))
old.covi6<-list(cov1,cov2,cov3,cov4,cov5,cov6)
k6<-list(old.mui6,old.covi6,old.pii6)

biglist<-list(k2,k3,k4,k5,k6)
biglist

table.report<-matrix(c(2,3,4,5,6),nrow=5,ncol=3)

for (i in 1:5){
  em<-em.norm(x,biglist[[i]][[1]],biglist[[i]][[2]],biglist[[i]][[3]])
  table.report[i,2]<-em$ML.est
  table.report[i,3]<-em$ML.est-(6*(i+1)-1)
}

table.report
plot(table.report[,1],table.report[,3],type='l')

em.best<-em.norm(x,biglist[[3]][[1]],biglist[[3]][[2]],biglist[[3]][[3]])
em.best

#Q1b-iii ploting with best choice of K
xseq<-seq(-1.1,0.8,0.02)
yseq<-seq(-0.12,1.05,0.02)
"zvalues"<-function(x.star){
  zvalues1<-em.best$mix.prop[1]*dmvnorm(x.star,em.best$means[[1]],em.best$covariances[[1]])+em.best$mix.prop[2]*dmvnorm(x.star,em.best$means[[2]],em.best$covariances[[2]])+em.best$mix.prop[3]*dmvnorm(x.star,em.best$means[[3]],em.best$covariances[[3]])+em.best$mix.prop[4]*dmvnorm(x.star,em.best$means[[4]],em.best$covariances[[4]])
  return(zvalues1)
}
em.best
zvalues.tot<-matrix(0,nrow=length(xseq),ncol=length(yseq))

for (i in 1:length(xseq)){
  for (j in 1:length(yseq)){
    zvalues.tot[i,j]<-zvalues(c(xseq[i],yseq[j]))
  }
}

contour(xseq,yseq,zvalues.tot,main='Contour Plot & Datapoints for K=4',xlab='x',ylab='y')
points(x[,1],x[,2],pch= 4 ,col='blue')
