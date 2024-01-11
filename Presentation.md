---
title: Projet C++
subtitle: Sujet "Finance", Pricer
author: 
- Jacques
- Thomas
- Tien-Thinh
date: vendredi 12 janvier 2024
toc: true
slide-level: 1
---

# Introduction
## Consignes
[1] Créer un programme pour déterminer le prix d’une option financière à l'aide de l'équation de Black, Scholes et Merton, puis à l'aide de la simulation de Monte Carlo.
 

# La formule de de Black-Scholes 
## La formule
### Block1
Supposons que $r$ et $vol$ sont constants, alors nous pouvons obtenir à l'aide du lemme d'Îto le prix d'un call européen selon l'équation: 
 $$C_{0} = S_0 N(d_1) - K\exp (-rT)N(d_2)$$
 où $d_1 = \frac{\ln(\frac{S_0}{K}) + (r + \frac{vol^2}{2})T}{vol\sqrt{T}}$ et $d_2 = d_1 - vol\sqrt{T}$

 et on en déduit le prix d'un put européen à l'aide de la formule de parité call/put:
 $$C_0-P_0 = S_0 - K\exp{(-rT)}$$



## Les Hypothèses  
### Block1
Blah blah


## Structure de code
qldfjk

# La méthode de Monte Carlo  
## Présentation de la méthode de Monte Carlo
kjdhfql

## Création d'un graphique en C++
![Notre simulation de prix](Mouvement Brownien.png){ width=75% }

## Difficulés rencontrées

# Le pricing d'options complexes

## Un code modulable
### Structure de code
Notre code repose sur l'utilisation de classe (POO) permettant une grande modularité :  
 - La classe permet de garder tous les paramètres de simulation
 - La fonction calculate permet d'effectuer les simulations  

## Difficulés rencontrées
### Penser le code pour des options plus complexes

### Pistes d'amélioration
 - Utilisation de la méthode Quasi Monte-Carlo qui permettrait de gagner du temps  
 - Implémenter des calculs en parallèle sur carte graphique  