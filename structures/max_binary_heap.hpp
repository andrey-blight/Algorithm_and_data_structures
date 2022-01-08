#pragma once
#include <iostream>
/*
Реализация максимальной двоичной кучи
*/
class BinaryHeap
{
private:
    int *heap; // Будем хранить кучу в виде одномерного массива
    size_t size;
    size_t max_size;
    void sift_up(size_t i)
    {
        // i-й элемент всплывает наверх если он больше родителя
        while (i != 0 && heap[i] > heap[(i - 1) / 2]) // Если элемент не находится в вершине и он больше родителя то меняем элементы местами
            std::swap(heap[i], heap[(i - 1) / 2]), i = (i - 1) / 2;
    }
    void sift_down(size_t i)
    {
        // i-й элемент опускается вниз если он меньше ребенка
        while (2 * i + 1 < size) // Пока левый сын существует
        {
            size_t left = i * 2 + 1, right = i * 2 + 2, j = left; // находим индексы левого и правого сына и записываем в j сына которого мы будем обменивать
            if (right < size && heap[right] > heap[left])
                j = right; // Если правый сын существует и он болше левого то в j записываем правого сына
            if (heap[i] >= heap[j])
                break;                   // Если текущий элемент больше или равен большему сына то ничего не делаем и выходим из цикла
            std::swap(heap[i], heap[j]); // Иначе меняем местами текущий элемент с большим сыном
            i = j;                       // Присваиваем текущий элемент большему сыну
        }
    }

public:
    BinaryHeap(size_t max_n) : heap(new int[max_n]), size(0), max_size(max_n) {} // Конструктор по максимальному количеству элементов в куче
    BinaryHeap(size_t n, int *a) : heap(new int[n]), size(n), max_size(n)
    {
        // Скопируем переданный массив в нашу кучу
        for (size_t i = 0; i < n; ++i)
            heap[i] = a[i];
        // Построим кучу за O(n)
        for (int i = n - 2 / 2; i >= 0; --i)
            sift_down(i);
    }
    int pop()
    {
        // Удаляем верхний элемент. Асимптотика O(log n)
        if (size == 0) // Если куча пустая то мы не можем оттуда ничего удалить и возвращаем -1
            return -1;
        int val = heap[0];                // Значение максимального элемента
        std::swap(heap[0], heap[--size]); // Меняем местами вершину с полседним элементом и уменьшаем размер на 1
        sift_down(0);                     // Просеиваем вершину вниз
        return val;                       // Возвращаем максимальное значение
    }
    void insert(int n)
    {
        // Добавляем элемент в кучу. Асимптотика O(log n)
        if (size == max_size) // Если текущий размер кучи равен максимальному то добавить элемент невозможно
            return;
        heap[size++] = n;  // Добавляем новый элемент в конец и увеличиваем размер на 1
        sift_up(size - 1); // Просеиваем вверх последний элемент
    }
    void print_heap()
    {
        // Выводим кучу в виде массива
        for (size_t i = 0; i < size; ++i)
            std::cout << heap[i] << ' ';
        std::cout << '\n';
    }
};