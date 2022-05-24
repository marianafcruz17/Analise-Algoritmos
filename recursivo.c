//RECURSIVOS

/*
f(n) = c + f(n-1) -> complexidade: O(n) - linear

f(n) = c * n + f(n-1) -> complexidade: O(n^2) - quadratico

f(n) = c + f(n/2) -> complexidade: O(log(n)) - logaritmica

f(n) = n + 2 * f(n/2) -> complexidade: O(nlog(n))

f(n) = c + 2 * f(n-1) -> complexidade: O(2^n) - exponencial

Fibonacci -> exponencial
Percorre arvore binária -> exponencial
for(i=0;i<n;i++){} -> complexidade: O(n) - linear
for(i=0;i<n;i=i/2){} -> complexidade: O(log(n)) - logaritmica

Boyer-Moore -> M * N 
    - melhor forma para pesquisar textos do dia a dia
KMP
    - melhor para quando tiver várias repetições de caracteres
Rabin Karp
    - melhor para quando tiver padrões grandes e quando não há a necessidade de extidão de resposta, podendo haver falso positivo
*/