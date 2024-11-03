EVIDENCIAS DE EJECUCION DEL CODIGO EN EL SERVIDOR GUANE-1 Y UNA MAQUINA LOCAL:

![Captura1](https://user-images.githubusercontent.com/93000699/234049493-3dbad24d-1ead-4a5c-ae1f-0cea88115951.PNG)
![Captura](https://user-images.githubusercontent.com/93000699/234049501-4b54d825-1b55-477c-9793-5154bbf248e5.PNG)


EXPLICACION DEL CODIGO:

The code above prompts the user to input a positive integer and then uses the OpenMP library to create a team of threads to sum up all the integers from 1 to the user inputted integer in parallel.
The parallel for directive distributes the iterations of the for loop across the threads in the team. The reduction clause is used to indicate that the variable "sum" should be shared among the threads, and each thread should maintain a private copy of the variable. The "+:" operator indicates that the private copies of "sum" should be added together at the end of the loop.
After the parallel loop completes, the final value of "sum" is printed to the console./*
