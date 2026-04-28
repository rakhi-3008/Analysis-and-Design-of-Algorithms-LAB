# Analysis and Design of Algorithms (ADA)

This repository contains implementations of important algorithms studied in ADA, along with their **Aim**, **Algorithm**, **Time Complexity**.
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
## 10. Binary Search

### Aim

To efficiently search an element in a sorted array using divide-and-conquer.

### Algorithm

```cpp
int binarySearch(int a[], int low, int high, int key){
    while(low <= high){
        int mid = (low + high) / 2;

        if(a[mid] == key)
            return mid;
        else if(a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
```
### Time Complexity

* Best Case: **O(1)**
* Worst Case: **O(nlogn)**

---
## 3. Insertion Sort

### Aim

To sort array elements using Insertion Sort.

### Algorithm

```cpp
void insertionSort(int a[], int n){
    for(int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}
```
### Time Complexity

* Best Case: **O(n)**
* Worst Case: **O(n^2)**

---

## 4. Merge Sort

### Aim

To sort array elements using Merge Sort with divide-and-conquer.

### Algorithm

```cpp
void mergeSort(int a[], int low, int high){
    if(low < high){
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
```
### Time Complexity
* Best Case: **O(n log n)**
* Worst Case: **O(n log n)**
### Space Complexity
* O(n)
 ---

 ## 5. Quick Sort

### Aim

To sort array elements using Quick Sort with partition technique.

### Algorithm

```cpp
void quickSort(int a[], int low, int high){
    if(low < high){
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}
```
### Time Complexity
* Best Case: **O(n log n)**
* Worst Case: **O(n^2)**
### Space Complexity
* O(1)
 ---

 ## 6. Kth Smallest Element 

### Aim

To find the kth smallest element in an array using partition method of Quick Sort.

### Algorithm

```cpp
int kthSmallestNumber(int arr[], int s, int e, int k){
    int p = partition(arr, s, e);

    if(p == k)
        return arr[p];
    else if(k < p)
        return kthSmallestNumber(arr, s, p - 1, k);
    else
        return kthSmallestNumber(arr, p + 1, e, k);
}
```
### Time Complexity
* Best Case: **O(n)**
* Average Case: **O(n)**
* Worst Case: **O(n²)**
### Space Complexity
* Average Case: **O(log n)**
* Worst Case: **O(n)**
---

## 10. Fractional Knapsack

### Aim

To maximize profit by selecting full or fractional items based on profit/weight ratio.

### Algorithm

```cpp
sort(items by profit/weight ratio descending);

for(i=0;i<n;i++){
    if(capacity >= wt[i]){
        profit += val[i];
        capacity -= wt[i];
    }
    else{
        profit += val[i] * ((float)capacity / wt[i]);
        break;
    }
}
```
### Time Complexity **O(n log n)**
### Space Complexity **O(1)**
---

## 11. Activity Selection

### Aim

To select maximum number of non-overlapping activities.

### Algorithm

```cpp
sort(activities by finish time);

select first activity;
last = 0;

for(i=1;i<n;i++){
    if(start[i] >= finish[last]){
        select activity i;
        last = i;
    }
}
```
### Time Complexity **O(n log n)**
### Space Complexity **O(1)**
---

## 12. Dijkstra Algorithm

### Aim

To find shortest path from source vertex to all vertices.

### Algorithm

```cpp
dist[source] = 0;

for(count=0; count<V-1; count++){
    u = minimumDistanceVertex();
    visited[u] = true;

    for(v=0; v<V; v++){
        if(!visited[v] && graph[u][v] &&
           dist[u] + graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
    }
}

```
### Time Complexity **O(V^2)**
### Space Complexity **O(V)**

---

## 13. Kruskal Algorithm

### Aim

To find Minimum Spanning Tree using greedy method.

### Algorithm

```cpp
sort(edges by weight);

for each edge(u,v):
    if(find(u) != find(v)){
        include edge;
        union(u,v);
    }

```
### Time Complexity **O(ElogE)**
### Space Complexity **O(V)**

---
## 14. Prim's Algorithm

### Aim

To find Minimum Spanning Tree starting from any vertex.

### Algorithm

```cpp
key[0] = 0;

for(count=0; count<V-1; count++){
    u = minimumKeyVertex();
    mst[u] = true;

    for(v=0; v<V; v++){
        if(graph[u][v] && !mst[v] &&
           graph[u][v] < key[v]){
            parent[v] = u;
            key[v] = graph[u][v];
        }
    }
}
```
### Time Complexity **O(V^2)**
### Space Complexity **O(V)**

---


✨ *All programs are implemented in C++ and focus on understanding algorithmic efficiency.*
