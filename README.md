---
title: Sujet "Finance"
subtitle: Pricer
author: Jacques ZHANG, Thomas ROUSSAUX et Tien-Thinh TRAN-THUONG
date: Decembre 2023
geometry: margin=2cm
---


# Consignes
Créer un programme pour déterminer le prix d’une option financière, ainsi que la stratégie de réplication dans le modèle de Black-Scholes-Merton. Dans la plupart des cas où les formules explicites ne s’appliquent pas,
on calculera ces prix par méthode de Monte-Carlo.

# Structure du code
## Réalisations
Pour répondre à la consigne, nous avons choisi de comparer le pricer par simulation de Monte-Carlo et celui par Black-Scholes.  
Afin que le code soit plus clair et épuré, nous avons organisé notre code sous forme de fichier header `.h` en utilisant la Programmation Orienté Objet (POO) étudié lors des cours et des TD de C++.  

## main.cpp
**main.cpp** importe ainsi les *classes* **MonteCarlo** et **BlackScholes** afin de créer respectivement les instances **my_monte_carlo** et **my_black_scholes**. On trouve alors les valeurs ... et ... qui ne sont pas égales mais restent cohérente avec les calculs vu en cours d'Instruments Financier à l'ENSAE.

# Difficultés rencontrées
## CMake
Pour gérer un projet d'une telle ampleur, nous ne pouvions pas utiliser `gcc` ou `g++` pour compiler les fichiers un par un. Nous avons donc fait appel à CMake :  
[1] *CMake is the de-facto standard for building C++ code, with over 2 million downloads a month. It’s a powerful, comprehensive solution for managing the software build process. Get everything you need to successfully leverage CMake by visiting our resources section.*

# To create this pdf
```
pandoc .\README.md -o README.pdf  
```


# Bibliographie
 1. CMake : https://cmake.org/