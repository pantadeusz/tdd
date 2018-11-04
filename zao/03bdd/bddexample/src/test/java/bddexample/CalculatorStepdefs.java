package bddexample;

import cucumber.api.PendingException;
import cucumber.api.java.Before;
import cucumber.api.java.en.Given;
import cucumber.api.java.en.Then;
import cucumber.api.java.en.When;

import java.util.List;

import static org.junit.Assert.assertEquals;

public class CalculatorStepdefs {
    Calculator calc;


    @Given("^we have calculator$")
    public void we_have_calculator() throws Exception {
        calc = new Calculator();
    }

    @Given("^we have first number equals (-?\\d+.?\\d*)$")
    public void we_have_first_number_equals(Double arg1) throws Exception {
        calc.addArg(arg1);
    }

    @Given("^we have second number equals (-?\\d+.?\\d*)$")
    public void we_have_second_number_equals(Double arg2) throws Exception {
        calc.addArg(arg2);
    }

    @Given("^we set arguments to:$")
    public void we_set_arguments_to(List<Double> arg1) throws Exception {
        calc.addArgs(arg1);
    }


    @When("^we add them$")
    public void we_add_them() throws Exception {
        calc.sum();
    }

    @Then("^the result shoud be (-?\\d+.?\\d*)$")
    public void the_result_shoud_be(Double arg1) throws Exception {
        assertEquals(arg1, calc.getResult(),0.01);
    }
}
