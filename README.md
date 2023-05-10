# 2022-2023-4GP-FRONZES-CHAKRI
## Description générale

Au cours de l'UF "Du capteur au banc de test" en 4ème année de Génie Physique à l'INSA Toulouse, nous avons réalisé une jauge de contrainte à base de graphite, low-tech, low-cost et transportable. Nous avons utilisé une carte Arduino Uno, un PCB, un module Bluetooth, un écran OLED, un flex sensor et conçu une application grâce à MIT App Inventor.

## Table des matières
* [Livrables](#livr)
* [Composants](#comp)
* [LTSpice](#spice)
* [PCB Shield](#pcb)
* [Application](#app)
* [Arduino](#ard)
* [Banc de test](#banc)
* [Datasheet](#data)
* [Améliorations](#amel)

<div id='livr'/>

## Livrables

Les livrables à l’issue de ce projet sont les suivants :

* Un exemple de circuit analogique auquel peut être relié le capteur, réalisé à l'aide du logiciel LTSpice
* Un PCB Shield
* Un code Arduino pour transmettre les mesures faites grâce au capteur à un écran OLED et à un module Bluetooth, connecté à un système Android
* Une application APK
* Un banc de test
* Une datasheet

<div id='comp'/>

## Composants

Les composants nécessaires à la réalisation du circuit analogique sont cités ci-dessous :

* Arduino Uno
* Amplificateur LTC1050
* Module Bluetooth HC05
* Ecran OLED 128x64
* Encodeur rotatif GT055
* Capteur en papier
* Résistances : 1 de 1 kOhms, 1 de 10 kOhms, 1 de 39 kOhms, 2 de 100 kOhms
* Capacités : 2 de 100 nF, 1 de 1 uF

<div id='spice'/>

## LTSpice

Le logiciel LTSpice nous a permis de simuler le circuit analogique dans lequel est intégré notre capteur. Le signal est filtré et amplifié par un LTC1050.

![spice](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/blob/main/LTSpice/Circuit%20LTSpice.PNG)

Ce circuit peut être retrouvé dans le dossier [LTSpice](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/tree/main/LTSpice).

<div id='pcb'/>

## PCB Schield

Afin de concevoir le PCB, nous avons commencé par dessiner le schéma électronique et ses composants sur KiCad, dans un fichier Schematic. Il s'agissait de relier les pins des composants à ceux de l'Arduino et de choisir leurs empreintes.

![schematic](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/blob/main/KiCad/KiCad_sch%C3%A9matique.png)

Dans un second temps, nous avons placé les composants sur le PCB, de sorte qu'ils ne se chevauchent pas, en s'assurant de la bonne largeur des pistes et des pins.

![pcb](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/blob/main/KiCad/KiCad_PCB.png)

Dans un troisième temps, Mme Crouzet nous a accompagnés dans l'impression physique du circuit, puis nous avons percé le PCB (trous de 0.8 mm pour l'ensemble des pins, exceptés ceux de l'Arduino qui font 1 mm).

Le dossier comportant tous les fichiers KiCad est disponible [ici](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/tree/main/KiCad).

<div id='app'/>

## Application

Les mesures réalisées grâce au capteur de graphite sont envoyées via le module Bluetooth sur une application Android APK, réalisée grâce à MIT App Inventor ([lien vers le site](https://appinventor.mit.edu/)).

Voici l'écran avec le graphique, c'est-à-dire la face avant :

![favant](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/blob/main/Bluetooth_Application/Front_Panel.jpg)

Et ci-dessous le schéma bloc de la face arrière :

![farrière](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/blob/main/Bluetooth_Application/Back_Panel.PNG)

Vous pouvez trouver le code de l'application dans le dossier [Application](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/tree/main/Bluetooth_Application).

<div id='ard'/>

## Arduino

L'ensemble du projet repose sur le code Arduino, qui relie l'ensemble des composants et des fonctions du système. Ce dernier récupère ainsi les valeurs de résistance du capteur de graphite et les stocke. Il permet leur affichage sur l'écran OLED et assure la connection au module Bluetooth, pour envoyer les données vers l'application.

[Ici](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/tree/main/Arduino_Program) se trouve le code Arduino.

<div id='banc'/>

## Banc de test

Pour vérifier le bon fonctionnement du capteur et rédiger notre datasheet, nous avons utilisé un banc de test préexistant, composé de demi-sphères de rayons variables. La feuille de papier où est déposé le graphite peut être pliée suivant la courbe de la demi-sphère, ce qui permet de mesurer la variation de résistance du capteur à intervalle régulier.

Les courbes de variation obtenues sont accessibles via la [datasheet](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/blob/main/Datasheet/Datasheet.pdf).

<div id='data'/>

## Datasheet

Elle a notamment été établie grâce à l'utilisation du banc de test. Nous avons mesuré les variations de résistance par rapport à la déformation pour les crayons HB et 2B. Pour chaque rayon de demi-sphère, nous avons effectué cinq mesures en traction puis calculé la moyenne de celles-ci. Nous avons reproduit le processus pour la compression. Il est important de noter que la résistance mesurée dépend de la quantité de graphite déposée sur le papier (donc de l'intensité avec laquelle on appuie en coloriant).

La datasheet est disponible [ici](https://github.com/MOSH-Insa-Toulouse/2022-2023-4GP-FRONZES-CHAKRI/blob/main/Datasheet/Datasheet.pdf).

<div id='amel'/>

## Améliorations

Sur le PCB, les pins pour brancher les pinces reliées à la feuille de papier sont trop proches de l'écran OLED, ce qui gêne un peu le branchement.

Concernant les fonctionnalités, nous aurions pu utiliser le potentiomètre digital, car il possède déjà un emplacement sur le PCB, mais nous avons manqué de temps pour le coder.

Nous aurions aussi pu tester plus de types de crayon afin de les inclure dans la datasheet, et comparer les valeurs que nous obtenons avec celles d'autres binômes, pour rendre la datasheet plus précise et plus juste.

