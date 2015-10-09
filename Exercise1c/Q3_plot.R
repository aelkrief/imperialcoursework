i=0
k=1
x=rep(0,360)
y=rep(0,360)
X=1/5
Y=1/3
while (i<(2*pi)){
  x[k]=cos(i)
  y[k]=0.64429054104497*sin(i)
  k=k+1
  i=i+(2*pi)/360
}
phi1<--2.867215
phi2<--0.798204
phi3<--0.797394
phi4<-1.321220
x1<-cos(phi1)
x2<-cos(phi2)
x3<-cos(phi3)
x4<-cos(phi4)
y1<-0.64429054104497*sin(phi1)
y2<-0.64429054104497*sin(phi2)
y3<-0.64429054104497*sin(phi3)
y4<-0.64429054104497*sin(phi4)

m1=(y1-Y)/(x1-X)
m2=(y2-Y)/(x2-X)
m3=(y3-Y)/(x3-X)
m4=(y4-Y)/(x4-X)
xvals1<-c(X,x1,-1.5,1.5)
xvals2<-c(X,x2, -1.5,1.5)
xvals3<-c(0,0.5)
xvals4<-c(X,x4,-1.5,1.5)
l1<-c(Y,y1,Y+m1*(-1.5-X),Y+m1*(1.5-X))
l2<-c(Y,y2,Y+m2*(-1.5-X),Y+m2*(1.5-X))
l3<-c(Y+m3*(0-X),Y+m3*(0.5-X))
l4<-c(Y,y4,Y+m4*(-1.5-X),Y+m4*(1.5-X))

plot(x,y,type='l')
abline(h=0,v=0)
lines(xvals1,l1,col='green')
lines(xvals2,l2,col='red')
lines(xvals3,l3,col='blue')
lines(xvals4,l4,col='orange')
