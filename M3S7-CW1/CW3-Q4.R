f<-function(x){
  f.x=exp(-x)*sin(x) + sinh(x)
  return(f.x)
}

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
