package pl.edu.pjatk.tau;

import org.jbehave.core.annotations.Given;
import org.jbehave.core.annotations.Then;
import org.jbehave.core.annotations.When;

import static org.hamcrest.CoreMatchers.equalTo;
import static org.junit.Assert.assertTrue;
import static org.mockito.BDDMockito.given;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.times;
import static org.mockito.Mockito.verify;

/**
 * To jest ta najważniejsza klasa do testów behawioralnych która implementuje opowieść (story)
 *
 * Zobacz, że ta jedna klasa może pasować do wielu opowieści.
 */


public class CartSteps {
    private Cart cart;
    Product product;
    int productCount;

    @Given("there is a product with price $price zl")
    public void fillCart(double price){
        // uwaga - antywzorzec - klasa Product nie powinna 
        // byc mockowana (zobacz zasady mockowania - link podalem na zajeciach)
        product = mock(Product.class);
        cart = new CartImpl();
        given(product.getPrice()).willReturn(price);
    }

    @When("$products products are added to cart")
    public void productsAdded(int products) {
        for (int i = 0; i < products; i++)
            cart.addProduct(product);
        productCount = products;
    }

    @Then("the summary price should be $summaryPrice")
    public void priceCalculated(double summaryPrice) {
        assertTrue(cart.getSummaryPrice() == summaryPrice);
        verify(product,times(productCount)).getPrice();
    }

}
