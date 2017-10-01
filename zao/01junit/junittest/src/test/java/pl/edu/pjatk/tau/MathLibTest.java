package pl.edu.pjatk.tau;

import org.junit.Assert;
import org.junit.Test;

public class MathLibTest {
    MathLib ml = new MathLibImpl();
    @Test
    public void testAdding() {
        Assert.assertEquals(4, ml.add(2,2));
        Assert.assertEquals("Adding 2 + 7",9, ml.add(2,7));
    }

    @Test(expected = ArithmeticException.class)
    public void testDivideByZero() throws ArithmeticException {
        ml.div(2,0);
    }

}
