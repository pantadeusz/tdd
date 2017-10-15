package pl.edu.puzniakowski.mocks.plotutils;
import org.junit.runner.RunWith;
import org.mockito.InOrder;
import org.mockito.Mock;
import static org.junit.Assert.*;
import static org.mockito.AdditionalMatchers.gt;
import static org.mockito.BDDMockito.given;
import static org.mockito.BDDMockito.then;
import static org.mockito.Mockito.*;

import org.junit.Before;
import org.junit.Test;
import org.mockito.junit.MockitoJUnitRunner;
import pl.edu.puzniakowski.mocks.plotters.PlotterDriver;

@RunWith(MockitoJUnitRunner.class)
public class PlotSquaresTest {
    PlotSquares plotSquares = new PlotSquares();

    @Mock
    PlotterDriver mockedPlotter;

    @Before
    public  void setup() {
        assertNotNull(mockedPlotter);
        plotSquares.setPlotterDriver(mockedPlotter);
        verify(mockedPlotter).resetPosition();
    }

    @Test
    public  void testDrawSquares() {
        int x0 = 10, y0 = 5, r = 7;
        when(mockedPlotter.getPositionX()).thenReturn(x0);
        when(mockedPlotter.getPositionY()).thenReturn(y0);
        //when(mockedPlotter.gotoXY(x0 - r, y0 - r)).thenReturn(); -- we don't do that!!

        plotSquares.drawSquareInPlace(r);
        InOrder inOrder = inOrder(mockedPlotter);
        inOrder.verify(mockedPlotter).getPositionX();
        inOrder.verify(mockedPlotter).getPositionY();
        inOrder.verify(mockedPlotter).gotoXY(x0 - r, y0 - r);
        inOrder.verify(mockedPlotter).gotoXY(x0 + r, y0 - r);
        inOrder.verify(mockedPlotter).gotoXY(x0 + r, y0 + r);
        inOrder.verify(mockedPlotter).gotoXY(x0 - r, y0 + r);
    }

    @Test(expected = IllegalArgumentException.class)
    public  void testEdgeConditionException() {
        int x0 = 100, y0 = 100, r = 7;
        when(mockedPlotter.getPositionX()).thenReturn(x0);
        when(mockedPlotter.getPositionY()).thenReturn(y0);
        doThrow(new IllegalArgumentException())
                .when(mockedPlotter)
                .gotoXY(gt(50), gt(50));
        plotSquares.drawSquareInPlace(r);
    }

    @Test
    public void testSetupBDDStyle() {
        given(mockedPlotter.resetPosition()).willReturn(true);
        mockedPlotter.resetPosition();


        int x0 = 10, y0 = 5, r = 7;
        when(mockedPlotter.getPositionX()).thenReturn(x0);
        when(mockedPlotter.getPositionY()).thenReturn(y0);
        plotSquares.drawSquareInPlace(r);

        
        then(mockedPlotter)
                .should()
                .getPositionX();
        then(mockedPlotter)
                .should()
                .getPositionX();
        then(mockedPlotter)
                .should(times(4))
                .gotoXY(anyInt(),anyInt());
    }


}
