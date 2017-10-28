Feature: AwesomeMul
  The demo shows how to test mutliplication app
  and how to write BDD tests in
  Cucumber

  Scenario: The multiplication of two numbers
    Given there is a multiplication object
    When numbers 5 and 3 are multiplied
    Then the result should be 15
