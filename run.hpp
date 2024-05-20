#pragma once

#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdlib>

void run() {
    
    ArrList pq(1000000); // Utworzenie instancji klasy ArrList o pojemnosci 1000000

    Timer timer;
    int choice = 0;
    while (choice != 3) {
        cout << "Wybierz strukture dla kolejki priorytetowej:" << endl;
        cout << "1. Tablica dynamiczna" << endl;
        cout << "2. Kopiec" << endl;
        cout << "3. Wyjdz" << endl;

        cin >> choice;
        system("cls");
        switch (choice) {
        case 1: {
            Structure* wsk = &pq; // Utworzenie wskaznika do klasy ArrList
            int choice1 = 0;
            while (choice1 != 6) {
                cout << "1. Dodaj element e o priorytecie p" << endl;
                cout << "2. Usuniecie i zwrocenie elementu o najwiekszym priorytecie" << endl;
                cout << "3. Zwrocenie (podejrzenie) elementu o najwiekszym priorytecie" << endl;
                cout << "4. Zmiana priorytetu elementu e na p" << endl;
                cout << "5. Zwrocenie rozmiaru" << endl;
                cout << "6. Wyjdz" << endl;
                cout << "7. Wygenerowanie losowych liczb:" << endl;

                cin >> choice1;

                switch (choice1) {
                case 1: {
                    system("cls");
                    int data;
                    int priority;
                    double totalElapsedTime = 0.0;
                    cout << "Podaj element: ";
                    cin >> data;
                    cout << "Podaj priorytet: ";
                    cin >> priority;

                    for (int i = 0; i < 100; ++i) {
                        ArrList pqCopy = pq; // Tworzenie kopii pq
                        Structure* wsk = &pqCopy; // Ustawienie wskaźnika na kopię
                        timer.start();
                        wsk->insert(data, priority);
                        timer.stop();
                        cout << i << ". " << wsk->getSize() << endl;
                        totalElapsedTime += timer.elapsed_milliseconds();
                    }

                    double averageTime = totalElapsedTime / 100.0;
                    cout << "Sredni czas wykonania operacji: " << averageTime << " ms" << endl;
                    break;
                }

                case 2: {
                    system("cls");
                    double totalElapsedTime = 0.0;
                    for (int i = 0; i < 100; ++i) {
                        ArrList pqCopy = pq; // Tworzenie kopii pq
                        Structure* wsk = &pqCopy; // Ustawienie wskaźnika na kopię
                        timer.start();
                        wsk->extractMax();
                        timer.stop();
                        cout << i << ". " << wsk->getSize() << endl;
                        totalElapsedTime += timer.elapsed_milliseconds();
                    }
                    double averageTime = totalElapsedTime / 100.0;
                    cout << "Sredni czas wykonania operacji: " << averageTime << " ms" << endl;
                    break;
                }
                case 3: {
                    system("cls");
                    double totalElapsedTime = 0.0;
                    for (int i = 0; i < 100; ++i) {
                        ArrList pqCopy = pq; // Tworzenie kopii pq
                        Structure* wsk = &pqCopy; // Ustawienie wskaźnika na kopię
                        timer.start();
                        wsk->peek();
                        timer.stop();
                        cout << i << ". " << wsk->getSize() << endl;
                        totalElapsedTime += timer.elapsed_milliseconds();
                    }
                    double averageTime = totalElapsedTime / 100.0;
                    cout << "Sredni czas wykonania operacji: " << averageTime << " ms" << endl;
                    break;
                }
                case 4: {
                    system("cls");
                    
                    int data;
                    int newPriority;
                    double totalElapsedTime = 0.0;
                    cout << "Podaj element: ";
                    cin >> data;
                    cout << "Podaj nowy priorytet: ";
                    cin >> newPriority;
                    for (int i = 0; i < 100; ++i) {
                        ArrList pqCopy = pq; // Tworzenie kopii pq
                        Structure* wsk = &pqCopy; // Ustawienie wskaźnika na kopię
                        timer.start();
                        wsk->modifyKey(data, newPriority);
                        timer.stop();
                        cout << i << ". " << wsk->getSize() << endl;
                        totalElapsedTime += timer.elapsed_milliseconds();
                    }
                    double averageTime = totalElapsedTime / 100.0;
                    cout << "Sredni czas wykonania operacji: " << averageTime << " ms" << endl;
                    break;
                }
                case 5: {
                    system("cls");
                    double totalElapsedTime = 0.0;
                    for (int i = 0; i < 100; ++i) {
                        ArrList pqCopy = pq; // Tworzenie kopii pq
                        Structure* wsk = &pqCopy; // Ustawienie wskaźnika na kopię
                        timer.start();
                        wsk->getSize();
                        timer.stop();
                        cout << i << ". " << wsk->getSize() << endl;
                        totalElapsedTime += timer.elapsed_milliseconds();
                    }
                    double averageTime = totalElapsedTime / 100.0;
                    cout << "Sredni czas wykonania operacji: " << averageTime << " ms" << endl;
                    break;
                }
                case 6: {
                    system("cls");
                    break;
                }
                case 7: {
                    system("cls");
                    int dataCount;
                    cout << "Podaj liczbe danych do wygenerowania (od 1 do 1000000): ";
                    cin >> dataCount;
                    wsk->generateRandomNumbers(dataCount);
                    break;
                }
                }
            }
            break;
        }
        case 2: {
            Heap heap(1000000); // Utworzenie instancji klasy Heap o pojemności 1000000
            Structure* wsk = &heap; // Utworzenie wskaźnika do klasy Heap
            int choice1 = 0;
            while (choice1 != 6) {
                cout << "1. Dodaj element e o priorytecie p" << endl;
                cout << "2. Usuniecie i zwrocenie elementu o najwiekszym priorytecie" << endl;
                cout << "3. Zwrocenie (podejrzenie) elementu o najwiekszym priorytecie" << endl;
                cout << "4. Zmiana priorytetu elementu e na p" << endl;
                cout << "5. Zwrocenie rozmiaru" << endl;
                cout << "6. Wyjdz" << endl;
                cout << "7. Wygenerowanie losowych liczb:" << endl;

                cin >> choice1;

                switch (choice1) {
                case 1: {
                    system("cls");

                    int data;
                    int priority;
                    double totalElapsedTime = 0.0;
                    cout << "Podaj element: ";
                    cin >> data;
                    cout << "Podaj priorytet: ";
                    cin >> priority;

                    for (int i = 0; i < 100; ++i) {
                        Heap heapCopy = heap; // Tworzenie kopii pq
                        Structure* wsk = &heapCopy; // Ustawienie wskaźnika na kopię
                        timer.start();
                        wsk->insert(data, priority);
                        timer.stop();
                        cout << i << ". " << wsk->getSize() << endl;
                        totalElapsedTime += timer.elapsed_milliseconds();
                    }

                    double averageTime = totalElapsedTime / 100.0;
                    cout << "Sredni czas wykonania operacji: " << averageTime << " ms" << endl;
                    break;
                }

                case 2: {
                    system("cls");
                    double totalElapsedTime = 0.0;
                    for (int i = 0; i < 100; ++i) {
                        Heap heapCopy = heap; // Tworzenie kopii pq
                        Structure* wsk = &heapCopy; // Ustawienie wskaźnika na kopię
                        timer.start();
                        wsk->extractMax();
                        timer.stop();
                        cout << i << ". " << wsk->getSize() << endl;
                        totalElapsedTime += timer.elapsed_milliseconds();
                    }
                    double averageTime = totalElapsedTime / 100.0;
                    cout << "Sredni czas wykonania operacji: " << averageTime << " ms" << endl;
                    break;
                }
                case 3: {
                    system("cls");
                    double totalElapsedTime = 0.0;
                    for (int i = 0; i < 100; ++i) {
                        Heap heapCopy = heap; // Tworzenie kopii pq
                        Structure* wsk = &heapCopy; // Ustawienie wskaźnika na kopię
                        timer.start();
                        wsk->peek();
                        timer.stop();
                        cout << i << ". " << wsk->getSize() << endl;
                        totalElapsedTime += timer.elapsed_milliseconds();
                    }
                    double averageTime = totalElapsedTime / 100.0;
                    cout << "Sredni czas wykonania operacji: " << averageTime << " ms" << endl;
                    break;
                }
                case 4: {
                    system("cls");
                    int data;
                    int newPriority;
                    double totalElapsedTime = 0.0;
                    cout << "Podaj element: ";
                    cin >> data;
                    cout << "Podaj nowy priorytet: ";
                    cin >> newPriority;
                    for (int i = 0; i < 100; ++i) {
                        Heap heapCopy = heap; // Tworzenie kopii pq
                        Structure* wsk = &heapCopy; // Ustawienie wskaźnika na kopię
                        timer.start();
                        wsk->modifyKey(data, newPriority);
                        timer.stop();
                        cout << i << ". " << wsk->getSize() << endl;
                        totalElapsedTime += timer.elapsed_milliseconds();
                    }
                    double averageTime = totalElapsedTime / 100.0;
                    cout << "Sredni czas wykonania operacji: " << averageTime << " ms" << endl;
                    break;
                }
                case 5: {
                    system("cls");
                    double totalElapsedTime = 0.0;
                    for (int i = 0; i < 100; ++i) {
                        Heap heapCopy = heap; // Tworzenie kopii pq
                        Structure* wsk = &heapCopy; // Ustawienie wskaźnika na kopię
                        timer.start();
                        wsk->getSize();
                        timer.stop();
                        cout << i << ". " << wsk->getSize() << endl;
                        totalElapsedTime += timer.elapsed_milliseconds();
                    }
                    double averageTime = totalElapsedTime / 100.0;
                    cout << "Sredni czas wykonania operacji: " << averageTime << " ms" << endl;
                    break;
                }
                case 6: {
                    system("cls");
                    break;
                }
                case 7: {
                    system("cls");
                    int dataCount;
                    cout << "Podaj liczbe danych do wygenerowania (od 1 do 1000000): ";
                    cin >> dataCount;
                    wsk->generateRandomNumbers(dataCount);
                    break;
                }
                }
            }
            break;
        }

        case 3: {
            return;
            break;
        }
        }
    }
}
