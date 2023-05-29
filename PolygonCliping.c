#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

int n,k=0;
float x[100], y[100], a[100], b[100];
float xmax,ymax,xmin,ymin;
void init(){
gluOrtho2D(-1000,1000,-1000,1000);
}
void lclip(float x1,float y1,float x2,float y2){
float m;
if(x2-x1){
m=(y2-y1)/(x2-x1);
}
else{
m=100000;
}
if(x1>=xmin && x2>=xmin){
a[k]=x2;
b[k]=y2;
k+=1;
}
if(x1<xmin && x2>=xmin){
a[k]=xmin;
b[k]=y1+m*(xmin-x1);
a[k+1]=x2;
b[k+1]=y2;
k+=2;
}
if(x1>=xmin && x2<xmin){
a[k]=xmin;
b[k]=y1+m*(xmin-x1);

k+=1;
}
}
void rclip(float x1,float y1,float x2,float y2){
float m;
if(x2-x1){
m=(y2-y1)/(x2-x1);
}
else{
m=100000;
}
if(x1<=xmax && x2<=xmax){
a[k]=x2;
b[k]=y2;
k+=1;
}
if(x1>xmax && x2<=xmax){
a[k]=xmax;
b[k]=y1+m*(xmax-x1);
a[k+1]=x2;
b[k+1]=y2;
k+=2;
}
if(x1<=xmax && x2>xmax){
a[k]=xmax;
b[k]=y1+m*(xmax-x1);
k+=1;
}
}
void tclip(float x1,float y1,float x2,float y2){
float m;
if(y2-y1){
m=(x2-x1)/(y2-y1);
}
else{
m=100000;
}
if(y1<=ymax && y2<=ymax){

a[k]=x2;
b[k]=y2;
k+=1;
}
if(y1>ymax && y2<=ymax){
a[k]=x1+m*(ymax-y1);
b[k]=ymax;
a[k+1]=x2;
b[k+1]=y2;
k+=2;
}
if(y1<=ymax && y2>ymax){
a[k]=x1+m*(ymax-y1);
b[k]=ymax;
k+=1;
}
}
void bclip(float x1,float y1,float x2,float y2){
float m;
if(y2-y1){
m=(x2-x1)/(y2-y1);
}
else{
m=100000;
}
if(y1>=ymin && y2>=ymin){
a[k]=x2;
b[k]=y2;
k+=1;
}
if(y1<ymin && y2>=ymin){
a[k]=x1+m*(ymin-y1);
b[k]=ymin;
a[k+1]=x2;
b[k+1]=y2;
k+=2;
}
if(y1>=ymin && y2<ymin){

a[k]=x1+m*(ymin-y1);
b[k]=ymin;
k+=1;
}
}
void display(void){
int i;

glBegin(GL_LINE_LOOP);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(xmin,ymin);
glVertex2f(xmin,ymax);
glVertex2f(xmax,ymax);
glVertex2f(xmax,ymin);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0f,0.0f,0.0f);
for(i=0;i<n;i++){
glVertex2f(x[i],y[i]);
}
glEnd();
glFlush();
//----- Left Clipping -----
k=0;
for(i=0;i<n-1;++i){
lclip(x[i],y[i],x[i+1],y[i+1]);
}
lclip(x[n-1],y[n-1],x[0],y[0]);
for(i=0;i<k;i++){
x[i]=a[i];
y[i]=b[i];
}
//----- Right Clipping -----
k=0;
for(i=0;i<n-1;++i){
rclip(x[i],y[i],x[i+1],y[i+1]);
}
rclip(x[n-1],y[n-1],x[0],y[0]);
for(i=0;i<n;i++){

x[i]=a[i];
y[i]=b[i];
}
//----- Top Clipping -----
k=0;
for(i=0;i<n-1;++i){
tclip(x[i],y[i],x[i+1],y[i+1]);
}
tclip(x[n-1],y[n-1],x[0],y[0]);
for(i=0;i<n;i++){
x[i]=a[i];
y[i]=b[i];
}
//----- Bottom Clipping -----
k=0;
for(i=0;i<n-1;++i){
bclip(x[i],y[i],x[i+1],y[i+1]);
}
bclip(x[n-1],y[n-1],x[0],y[0]);
for(i=0;i<n;i++){
x[i]=a[i];
y[i]=b[i];
}
}
void my_key_events(unsigned char key,int x,int y){
switch(key){
case 'c' : case 'C' :
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINE_LOOP);
glColor3f(0.0f,0.0f,1.0f);
glVertex2f(xmin,ymin);
glVertex2f(xmin,ymax);
glVertex2f(xmax,ymax);
glVertex2f(xmax,ymin);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.0f,1.0f,0.0f);
for(int i=0;i<n;i++){

glVertex2f(a[i],b[i]);
}
glEnd();
glFlush();
break;
}
}
int main(int argc, char** argv){
printf("Enter the number of vertices of polygon:");
scanf("%d",&n);
int i;
printf("Enter the co-ordinates:");
for(i=0;i<n;i++){
scanf("%f%f",&x[i],&y[i]);
}
printf("Enter the clipping boundary:");
scanf("%f%f%f%f",&xmin,&xmax,&ymin,&ymax);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(200,200);
glutCreateWindow("Sutherland Hodgman");
gluOrtho2D(-100,100,-100,100);
glutDisplayFunc(display);
glutKeyboardFunc(my_key_events);
glutMainLoop();
return 0;
}