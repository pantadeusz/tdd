Feature: Calculator for performing calculation
As a: programmer
In order to: show how to do BDD
I: would like to write some BDD style tests


Scenario Outline: Adding two numbers

Given we have calculator
And we have first number equals <a>
And we have second number equals <b>
When we add them
Then the result shoud be <result>

Examples:
   | a | b  | result |
   |10 | 20 |   30   |
   | 0 |  0 |    0   |
   |20 | 20 |   40   |
   |0.5| 1.5|   2.0  |
   |-0.5| 1.5|   1  |
   |0.5| -1.5|  -1  |


Scenario: Operations on multiple numbers at once

Given we have calculator
And we set arguments to:
  |4|
  |5|
When we add them
Then the result shoud be 9

Scenario: Getting results without calculations

Given we have calculator
And we have 1 element in arguments
Then the result shoud be available

Scenario: Getting last element from arguments

Given we have calculator
And we have 2 elements in arguments
Then the result shoud be available
