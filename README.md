# Lem-in
Lem-in is a School 21(Ecole 42) project. The goal of this project is to find the quickest way to get ants across the farm.

* Quickest way means the solution with the least number of lines, respecting the
output format requested below.

* Obviously, there are some basic constraints. To be the first to arrive, ants will need
to take the shortest path (and that isn’t necessarily the simplest). They will also
need to avoid traffic jams as well as walking all over their fellow ants.

* At the beginning of the game, all the ants are in the room **##start**. The goal is
to bring them to the room **##end** with as few turns as possible. Each room can
only contain one ant at a time. (except at **##start** and **##end** which can contain
as many ants as necessary.)

* Сonsidered that all the ants are in the room **##start** at the beginning of the game.

* At each turn you will only display the ants that moved.

* At each turn you can move each ant only once and through a tube (the room at
the receiving end must be empty).

* You must to display your results on the standard output in the following format:

![lem-in](/README_src/format.png)

x, z, r represents the ants’ numbers (going from 1 to number_of_ants) and y,
w, o represents the rooms’ names.

* Example 1:
```
[start]-[1]-[2]-[end]
```

![lem-in](/README_src/example1.png)

* Example 2.1:
```
 [start]
  /   \
[1]   [2]
 |     |
 |    [3]
  \   /
  [end]
   ```


![lem-in](/README_src/example2_1.png)

* In example 2.1, it is not required to use all paths, (you are free to do so as long as
the result does not have more lines, in some cases, however, it would be unwise to
do so) However, you MUST use several paths if this is necessary (see example 2.2).

* Example 2.2:

![lem-in](/README_src/example2_2.png)

* Finally, asked that your algorithm be able to use the best combination of paths
according to the number of ants in cases such as the one presented below.

* Example 3:
```
     [start]
     /  |
  [3]  [1]--[5]
   |    |    |
  [4]--[2]  [6]
        |  /
      [end]
```

![lem-in](/README_src/example3.png)

## Instructions
* You have to handle errors in a sensitive manner. In no way can your program quit
in an unexpected manner (Segmentation fault, bus error, double free, etc).
* Your program cannot have memory leaks.
* You are allowed to use **only** the following functions.
```
◦ malloc
◦ free
◦ read
◦ write
◦ strerror
◦ perror
◦ exit
```

## Decision

This project is being solved using graph theory. The solution is based on the [Suurballe Algorithm](http://www.macfreek.nl/memory/Disjoint_Path_Finding).
Suurballe Algorithm is based on the [Bellman Ford Algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm).

## Project Structure

This project consists of five parts:

* Libft - A library that contains useful native functions (`ft_printf`, `ft_split`, `ft_atoi`, `ft_itoa`, varios `str`
functions (`ft_strcpy`, `ft_strdub`, `ft_strcmp` etc.))
* For_test - part for test this project.

## Installation

Clone repository and then go into the created directory and run the following command:

```
make
```

## Usage

```
Usage: ./lem-in [-flags] < <lem-in_map>
                -f <lem-in_map> - put the map as an argument
                -w alternative output
```
## Test

To test this project you can get maps from `for_test/maps` dir. You can also use different shell scripts from `for_test` folder. They have their own `usage`
