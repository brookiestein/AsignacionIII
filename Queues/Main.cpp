#include <clocale>
#include <print>

#include "PrintJob.hpp"
#include "Queue.hpp"

int main()
{
    // Es importante establecer una locale en español para que 
    // la terminal de Windows muestre bien las tildes.
    std::setlocale(LC_ALL, "es_DO.UTF-8");
    Queue queue; // Sólo se permiten 10 trabajos por defecto, se puede cambiar en el constructor.

    queue.Push(new PrintJob("Sofía", 12));
    queue.Push(new PrintJob("Brayan", 3));
    queue.Push(new PrintJob("Manuel", 2));
    queue.Push(new PrintJob("Rafelina", 5));
    queue.Push(new PrintJob("Stephanye", 7));
    queue.Push(new PrintJob("Nieves", 4));
    queue.Push(new PrintJob("Jeff", 5));
    queue.Push(new PrintJob("Mia", 1));
    queue.Push(new PrintJob("Scott", 2));
    queue.Push(new PrintJob("Marco", 6));
    queue.Push(new PrintJob("Miguelina", 7)); // Este debería fallar.
                                              // Dado que estoy asignando la memoria dinámica on-the-fly,
                                              // me parece perfecto el comportamiento por defecto del método
                                              // push(): liberar la memoria si falla.
                                              // Si este no es el comportamiento deseado, puede pasarle false
                                              // como segundo parámetro para evitar esta liberación de memoria.
    queue.PrintAll();

    queue.Push(new PrintJob("Marco", 6));
    queue.Push(new PrintJob("Scott", 2));
    queue.Push(new PrintJob("Mia", 1));
    queue.PrintAll();
}