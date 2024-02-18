# Running the Code

To execute the code, follow these steps:

1. Navigate to the `cpp` directory:

    ```
    cd cpp
    ```

2. Run the make command to compile and execute the code:

    ```
    make run
    ```

3. Once the execution in the `cpp` directory is completed, navigate to the `swing` directory:

    ```
    cd ../swing
    ```

4. Again, run the make command to compile and execute the code:

    ```
    make run
    ```

These steps will compile and run the code in both the `cpp` and `swing` directories respectively.

To execute different parts of the code, in the main file, change the #define statements to the desired part of the code and re-run the make command.

This codes cover the c++ TP until the eleventh question, and the whole swing TP. Some implementations have just the .h header file, since the implementation is very simple and the code is self-explanatory.

--------------------------------------------------------------------------------

# Question answers
**4.1) Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?**

We call them abstract methods. They are declared with the keyword virtual and the suffix = 0. 

**4.2) Si vous avez fait ce qui précède comme demandé, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?**

Since we have an abstract method, we can't instantiate the class anymore.

**5.1) Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?**

The property is called polymorphism. It allows us to call the method of the derived class through a pointer of the base class, using the castings.

**5.2) Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?**

To use polymorphism in C++, we need to declare the methods as virtual in the base class. We also need to use pointers to the base class to call the methods of the derived class.

**5.3) Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.**

In the array, you should use pointers to objects of the base class (MULTIMEDIA). This ensures that the objects keep their specific type info.

In Java, arrays can hold different object types directly because Java uses reference types, unlike C++, which uses value passages.

**7.1) Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit les objets ? Modifiez le code de manière à l'éviter.**

You should delete the pointers to the objects in the array. To do this, you can use the delete[] operator in the destructor of the base class. By doing this, you already protect the program classes from memory leaks.

**7.2) La copie d'objet peut également poser problème quand ils ont des variables d'instance qui sont des pointeurs. Quel est le problème et quelles sont les solutions ? Implementez-en une.**

This problem arises when we perform a shallow copy. In this case, pointers point to the same address, and the object might be destroyed multiple times. A good solution is to redefine the copy operators to perform a deep copy.

**8) Le groupe ne doit pas détruire les objets quand il est détruit car un objet peut appartenir à plusieurs groupes (on verra ce point à la question suivante). On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.**

The list of objects should be a list of pointers to objects because the objects can be of different types. In C++, we need to use pointers to objects to store them in the same list, then, if you just delete the pointer from the group and not what is being pointed. In Java, the object will be destroyed when no one points to it anymore.

**10) Les méthodes précédentes permettent d'assurer la cohérence de la base de données car quand on crée un objet on l'ajoute à la table adéquate. Par contre, ce ne sera pas le cas si on crée un objet directement avec new (il n'appartiendra à aucune table). Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux ?**

To protect the access, we turn the constructors of the previouses groups in protected. This way, only the classes that inherit from them can create new objects. I'm not applying this in my code to not derange the implementation of previous questions.



