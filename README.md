---
title: Sujet "Finance"
subtitle: Pricer
author: Jacques ZHANG, Thomas ROUSSAUX et Tien-Thinh TRAN-THUONG
date: Decembre 2023
geometry: margin=2cm
---


# Consignes
Créer un programme pour déterminer le prix d’une option financière à l'aide de l'équation de Black, Scholes et Merton,
puis à l'aide de la simulation de Monte Carlo.

# Structure du code
## Réalisations
Pour répondre à la consigne, nous avons choisi de comparer le pricing par simulation de Monte-Carlo et celui par Black-Scholes.
Le pricing a été réalisé en fonction des variables suivante:  
 - S: prix du sous-jacent à l'instant initial
 - vol: volatilité du sous-jacent en année supposé constant
 - r: taux d'intérêt risque neutre en année supposé constant
 - K: strike de l'option
 - T: date de maturité de l'option en année  
Nous avons réalisé le pricing d'options vanilles européennes à l'aide de ces deux méthodes et avons comparé les résultats.

## Monte Carlo
Nous avons:
$\begin{equation}\LARGE
\frac{C_t}{B_t} = \mathbb{E}_{\mathbb{Q}}[\frac{C_T}{B_T}\mid F_t]
\end{equation}$  
$\Large C_{0,i} = \exp (-\int^{T}_{0}r_s ds) C_{T,i} = \exp (-rT) C_{T,i}$
$\Large \hat{C_0} = \frac{1}{M}\sum^{M}_{i=1} C_{0,i}$
$5$  

## Black Scholes
$\large dS_t = rS_tdt+\sigma S_tdW_t$

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