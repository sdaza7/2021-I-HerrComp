#include <iostream>

 void print_array(const double data[], const int & size);

 int main()
 {
 const int NX = 2, NY = 3, NZ = 4;
   double *x, y[NY]={0}, z[NZ]={0}; //Se inicializan los arreglos
   x = new double [NX] {0}; //Se inicializa el arreglo del puntero x
     //Se inicializan las variables ii, jj y kk
   int ii=0;
   int jj=0;
   int kk=0;
   print_array(x, NX);
   print_array(y, NY);
   print_array(z, NZ);
   std::cout << std::endl;

   for (ii = 0; ii < NX; ++ii) {
     x[ii] = ii; //En este for se debe usar la variable ii en vez de jj
   }
      //Se observa que z, y son arreglos contiguos, estando z antes que y, se ordenan de la forma: z[0]z[1]z[2]z[3]y[0]y[1]y[2]
   print_array(x, NX); //El tamaño del arreglo x es de NX, no NZ, al ser NZ mayor, está tomando valores que no pertenecen al arreglo. Se corrige a NX.
   print_array(y, NY);
   print_array(z, NZ+NY); //Parece un error, pero realmente está mostrando la impresión de valores de z y de y, los cuales son contiguos.
   std::cout << std::endl;

   for (jj = 0; jj < NY; ++jj) {
       //Debido a que en ambos casos se asignan valores de jj y el tamaño de jj es de NY, se debe utilizar un if para el x[jj] tal que se limite tamaño para que coincida con el de x (NX)
       if(jj<NX)
       {
           x[jj] = jj; //Se está usando la variable jj, no ii
       }
     y[jj] = jj;
   }
      //Se observa que z, y son arreglos contiguos, estando z antes que y, se ordenan de la forma: z[0]z[1]z[2]z[3]y[0]y[1]y[2]
   print_array(x, NX); //Debido a que la dirección de memoría de x se encuentra en el stack, los valores no son continuos, por lo que imprimir estos valores no tendría sentido. Se imprime x con tamaño NX.
   print_array(y-NZ, NZ); //Esto tiene sentido, debido a que y, z son contiguos, por lo tanto, se estaría imprimiendo realmente al arreglo z.
   print_array(z+NZ, NY); //Se expresa de esta forma, dejando solamente z+NZ y a NY, para imprimir un arreglo que correspondería realmente a y debido a la contiguidad de los arreglos.
   std::cout << std::endl;

   for (kk = 0; kk < NZ; ++kk) { //Se está usando la variable jj en vez de kk
//       //Debido a que los arrays tienen diferentes tamaños, se utilizan condicionales para su ejecución, de esta forma se limita el tamaño para que coincida con los tamaños de X (NX)  y Y (NY)
       if (kk<NX)
       {
           x[kk] = kk; //Se está usando la variable kk, no ii
       }
       if(kk<NY)
       {
           y[kk] = kk; //Se está usando la variable kk, no jj
       }
           z[kk] = kk; //Se está usando la variable kk, no ii
   }
   //Se observa que z, y son arreglos contiguos, estando z antes que y, se ordenan de la forma: z[0]z[1]z[2]z[3]y[0]y[1]y[2]
   print_array(x, NX);
   print_array(y, NY);
   print_array(z, NZ);
   std::cout << std::endl;
   std::cout << std::endl;
   std::cout << "Dirección de Memoría de X" << "\n";
    for(int a = 0; a<NX;++a)
   {
       std::cout<< (x+a) << "\n";
   }

    std::cout << "Dirección de Memoría de Z" << "\n";
        for(int b = 0; b<NZ;++b)
   {
       std::cout<< (z+b) << "\n";
   }

    std::cout << "Dirección de Memoría de Y" << "\n";
        for(int c = 0; c<NY;++c)
   {
       std::cout<< (y+c) << "\n";
   }
//AL final, es necesario despejar la memoria que se utilizó para el pointer x.
   delete [] x;

   return EXIT_SUCCESS;
}

 void print_array(const double data[], const int & size)
{
     std::cout << std::endl;
   for (int ll = 0; ll < size; ++ll) //Ya se había usado la variable ii, por lo tanto, es mejor definir otra variable como ll en su lugar
   {
     std::cout << data[ll] << "  " ;
   }
}
