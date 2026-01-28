# Analysis-and-Design-of-Algorithms-LAB
This repository contains implementations of important algorithms studied in ADA, along with their Aim, Algorithm, Time Complexity.
---

## 1. Power of x^n using Binary Exponentiation (Recursive)

### Aim

To efficiently compute the value of (x^n) using divide-and-conquer.

### Algorithm

```cpp
int power(int x, int n){
    if(n == 0)
        return 1;

    int half = power(x, n / 2);

    if(n % 2 == 0)
        return half * half;
    else
        return x * half * half;
}
```

### Time Complexity

* Time: **O(log n)**
* Space: **O(log n)** (recursion stack)


---

## 2. Permutations of a String

### Aim

To generate all possible permutations of a given string using recursion.

### Algorithm

```cpp
void permutations(char arr[], int n, int k){
    if(k == n){
        for(int i = 0; i < n; i++)
            cout << arr[i];
        cout << endl;
        return;
    }

    for(int i = k; i < n; i++){
        swap(arr[i], arr[k]);
        permutations(arr, n, k + 1);
        swap(arr[i], arr[k]); // backtracking
    }
}
```

### Time Complexity

* Time: **O(n × n!)**
* Space: **O(n)**


---

## 3. Horner’s Rule (Recursive)

### Aim

To evaluate a polynomial efficiently using Horner’s Rule.

### Algorithm

```cpp
double hornerRecursive(double A[], int n, double a, int index = 0){
    if(index == n)
        return A[index];

    return A[index] + a * hornerRecursive(A, n, a, index + 1);
}
```

### Time Complexity

* Time: **O(n)**
* Space: **O(n)** (recursive)


---

## 4. Tower of Hanoi

### Aim

To solve the Tower of Hanoi problem using recursion.

### Algorithm

```cpp
void towerOfHanoi(int n, char source, char destination, char auxiliary){
    if(n == 0)
        return;

    towerOfHanoi(n - 1, source, auxiliary, destination);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, auxiliary, destination, source);
}
```

### Time Complexity

* Time: **O(2^n)**
* Space: **O(n)**


---

## 5. Bubble Sort (Time Analysis)

### Aim

To sort an array using Bubble Sort and measure average execution time.

### Algorithm

```cpp
void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

### Time Complexity

* Time: **O(n²)**
* Space: **O(1)**


---

## 6. Missing Number using XOR

### Aim

To find a missing number from consecutive integers using bitwise XOR.

### Algorithm

```cpp
int findMissing(int arr[], int n){
    int xor1 = 0, xor2 = 0;

    for(int i = 1; i <= n; i++)
        xor1 ^= i;

    for(int i = 0; i < n - 1; i++)
        xor2 ^= arr[i];

    return xor1 ^ xor2;
}
```

### Time Complexity

* Time: **O(n)**
* Space: **O(1)**


---

## 7. Ball Tip Count (Recursive)

### Aim

To count the number of tips until velocity becomes less than or equal to 1.

### Algorithm

```cpp
int tip(double v){
    if(v <= 1)
        return 0;

    return 1 + tip(v * 0.575);
}
```

### Time Complexity

* Time: **O(v)**
* Space: **O(v)**


---

## 8. Truth Table Generation

### Aim

To generate all combinations of truth values for n variables.

### Algorithm

```cpp
void truthTable(char arr[], int n, int k){
    if(k == n){
        for(int i = 0; i < n; i++)
            cout << arr[i];
        cout << endl;
        return;
    }

    arr[k] = 'T';
    truthTable(arr, n, k + 1);

    arr[k] = 'F';
    truthTable(arr, n, k + 1);
}
```

### Time Complexity

* Time: **O(2^n)**
* Space: **O(n)**


---

## 9. Linear Search (Time Analysis)

### Aim

To search for an element in an array using linear search and analyze execution time.

### Algorithm

```cpp
int linearSearch(int arr[], int n, int target){
    for(int i = 0; i < n; i++){
        if(arr[i] == target)
            return i;
    }
    return -1;
}
```

### Time Complexity

* Best Case: **O(1)**
* Average Case: **O(n)**
* Worst Case: **O(n)**
* Space: **O(1)**


---

✨ *All programs are implemented in C++ and focus on understanding algorithmic efficiency and recursion behavior.*

