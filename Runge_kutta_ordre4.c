/************************************Runge kutta ordre 4**********************************************************/
//Ceci est le test des exercices donnees dans le cahier 
#include<stdio.h>
#include<math.h>

// float f1(float t,float y1, float y2)
// {
//     return -4*y1-2*y2+cos(t)+4*sin(t);
// }
// float f2(float t,float y1, float y2)
// {
//     return 3*y1+y2-3*sin(t);
// }

float f1(float y1,float y2)
{
    return -4*y1+3*y2+6;
}

float f2(float y1,float y2)
{
    return -2.4*y1+1.6*y2+3.6;
}

void affichage(int i,float t, float y1,float y2)
{
    printf("j\tt[j]\t\tw1[j]\t\tw2[j]\n");
    printf("%d\t%.6f\t%.6f\t%.6f\n",i,t,y1,y2);
}

void main()
{
   float a,b,n;

   //nombre d'equation diff dans le systeme
   const int m=2;
   
    //valeur de a
     printf("Entrer la valeur de a: ");scanf("%f",&a);
	 
	 //valeur de b
	 printf("Entrer la valeur de b: ");scanf("%f",&b);

     //valeur de n:nombre d'iteration
     printf("Entrer la valeur de n: ");scanf("%f",&n);
     
     //valeur de alpha:conditions initiales
     float alpha1=0,alpha2=0;
     printf("Entrer alpha1 initial(alpha[1][0]): ");scanf("%f",&alpha1);
     printf("Entrer alpha2 initial(alpha[2][0]): ");scanf("%f",&alpha2);

     //valeur de h et de t
     float h=(b-a)/n,t=a;
    //valeur des w0 initiaux w1,0 et w2,0
    float w1=alpha1,w2=alpha2;
    
    //affichage des elements
    int i=0;
    affichage(i,t,w1,w2);

    //incrementation de i
    i++;
    
    //declaration et initialisation des k1,k2,k3,k4
    float k1[100],k2[100],k3[100],k4[100];
    
    //Exercice nomen zo
    // //premierk premier element
    // k1[0]=h*f1(t,w1,w2);
    // //premierk deuxieme element
    // k1[1]=h*f2(t,w1,w2);
    
    // // // d2euxiemek premier element
    //  k2[0]=h*f1(t+(h/2),w1+(k1[0]/2),w2+(k1[1]/2));
    
    // // //deuxiemek deuxieme lement
    //  k2[1]=h*f2(t+(h/2),w1+(k1[0]/2),w2+(k1[1]/2));
     
    // // //troisiemek premier lement
    //  k3[0]=h*f1(t+(h/2),w1+(k2[0]/2),w2+(k2[1]/2));

    // // //troisiemek deuxieme lement
    //  k3[1]=h*f2(t+(h/2),w1+(k2[0]/2),w2+(k2[1]/2)); 

    // // //quatriemek premier lement
    //  k4[0]=h*f1(t+h,w1+k3[0],w2+k3[1]);
    
    // // //quatriemek deuxieme lement
    //  k4[1]=h*f2(t+h,w1+k3[0],w2+k3[1]);

    //Premier exercice le misy intensite du courant iny
    //premierk premier element
    k1[0]=h*f1(w1,w2);
    //premierk deuxieme element
    k1[1]=h*f2(w1,w2);
     // d2euxiemek premier element
     k2[0]=h*f1(w1+(k1[0]/2),w2+(k1[1]/2));
    
    // // //deuxiemek deuxieme lement
     k2[1]=h*f2(w1+(k1[0]/2),w2+(k1[1]/2));   
     
    // // //troisiemek premier lement
     k3[0]=h*f1(w1+(k2[0]/2),w2+(k2[1]/2));

    // // //troisiemek deuxieme lement
     k3[1]=h*f2(w1+(k2[0]/2),w2+(k2[1]/2)); 
     

    // // //quatriemek premier lement
     k4[0]=h*f1(w1+k3[0],w2+k3[1]);
    
    // // //quatriemek deuxieme lement
     k4[1]=h*f2(w1+k3[0],w2+k3[1]);

    // // //modification de w1
     w1+=(k1[0]+2*k2[0]+2*k3[0]+k4[0])/6;
     w2+=(k1[1]+2*k2[1]+2*k3[1]+k4[1])/6;
    
    // // //incrementation de t
      t+=i*h;

    //affichage des elements suivants
    affichage(i,t,w1,w2);   

}