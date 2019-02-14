cmake_minimum_required(VERSION 3.12)
project(CPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(array)
include_directories(hw3)
include_directories(hw4)
include_directories(hw5)
include_directories(linkedlist)
include_directories(queue)
include_directories(stack)

add_executable(CPP
        301_lab/lab2.cpp
        301_lab10/lab10.cpp
        301_lab2/lab2.cpp
        301_lab3/lab3.cpp
        301_lab4/main.cpp
        301_lab5/main.cpp
        301_lab6/lab6.cpp
        301_lab7/lab7.cpp
        301_lab8/lab8.cpp
        array/main.cpp
        array/SortedList.h
        array/UnsortedList.h
        AVLTree/AVLTree.cpp
        binarySearchTree/tree.cpp
        "circular linked list/circularLinkedList.cpp"
        "doubly linkedlist/doublyLinkedlist.cpp"
        factorial/factorial.cpp
        hw3/main.cpp
        hw3/MyDLL.h
        hw4/main.cpp
        hw4/Tree.h
        hw5/AVLTree.h
        hw5/main.cpp
        hw5/Tree.h
        linkedlist/main.cpp
        linkedlist/MyList.h
        queue/main.cpp
        queue/MyQueue.h
        stack/main.cpp
        stack/MyStack.h
        standalone_linkedlist/standalone_linkedlist.cpp
        standalone_pointerQueue/queue.cpp
        standalone_pointerStack/stack.cpp
        standalone_queue/queue.cpp
        standalone_sortedList/sortedList.cpp
        standalone_stack/stack.cpp
        standalone_unsortedList/unsortedList.cpp)
