# 🚀 Shortest Path Finder

### 👨‍💻 Developed by Team NULL POINTERS

**Team Lead:** Swaraj Gairola

---

## 📌 Project Overview

The **Shortest Path Finder** is a web-based application that visualizes and computes the shortest path between nodes in a graph using multiple algorithms. It allows users to input custom graphs and observe how different algorithms determine the optimal path.

---

## ⚡ Features

* Visual graph representation using Vis.js
* Supports multiple algorithms:

  * Dijkstra Algorithm
  * Bellman-Ford Algorithm
  * Floyd-Warshall Algorithm
* User-defined graph input
* Source & destination selection
* Real-time shortest path result
* Handles edge cases (like no path available)

---

## 🧠 Algorithms Used

### 🔸 Dijkstra Algorithm

* Works for graphs with non-negative weights
* Efficient for single-source shortest path

### 🔸 Bellman-Ford Algorithm

* Handles negative edge weights
* Detects negative cycles

### 🔸 Floyd-Warshall Algorithm

* Computes all-pairs shortest paths
* Useful for dense graphs

---

## 🖥️ Tech Stack

**Frontend:**

* HTML
* CSS
* JavaScript
* Vis.js

**Backend:**

* C++

---

## 📂 Project Structure

Shortest-Path-Finder/
│── index.html
│── style.css
│── script.js
│── BACKEND/
│     └── server.cpp
│── README.md

---

## ▶️ How to Run the Project

### 1️⃣ Clone the Repository

git clone https://github.com/swarajgairola-2912/Shortest-Path-Finder.git

### 2️⃣ Open Frontend

Open index.html in your browser

### 3️⃣ Run Backend (if applicable)

g++ server.cpp -o server
./server

---

## 🧪 Sample Input

0 1 4
0 2 1
2 1 2
1 3 1
2 3 5
3 4 3

---

## 🎯 Output

* Displays shortest path
* Highlights path in graph
* Shows total cost

---

## 💡 Future Enhancements

* Animated step-by-step visualization
* Better UI/UX design
* Web-based backend integration (Flask/Node.js)
* Random graph generator

---

## 📸 Screenshots

<img width="1474" height="879" alt="Screenshot 2026-04-13 215408" src="https://github.com/user-attachments/assets/6c88a1a1-3ef1-4aed-b295-049b29cf4d03" />

<img width="1014" height="867" alt="Screenshot 2026-04-13 215446" src="https://github.com/user-attachments/assets/f493b1c4-57d6-483a-a133-299c0a671884" />



---

## 📌 Conclusion

This project demonstrates the practical implementation and visualization of fundamental graph algorithms, helping users understand how shortest path algorithms work in real-world scenarios.

---

## ⭐ Show Your Support

If you like this project, give it a ⭐ on GitHub!
