# Flexible Particle System

## Table of Contents
* [General info](#general-info)
* [Todo](#todo)
* [Controls](#controls)
* [Technologies](#technologies)
* [Running](#running)

## General info
3D Particle system based on CPU computing with multithreading. 
Flexible architecture of the system alllows you to creating advanced physics simulations.
System is inspired by great article "Flexible particle system" written by Bartosz Filipek. https://www.bfilipek.com 

## Todo

Faster N body simulation updater

Unit Tests for updaters

Demo on Youtube

GUI (QT?)

## Controls
W/S - forward/backward
mouse - rotating
N/M - slow down/speed up simulation
B - stop simulation
Esc - exit

## Technologies
C++ 17

OpenGl 4.6.0

## Running
First create makefile using qmake:

`qmake app.pro`

then compile project:

`make`

and finaly:

`./app`
