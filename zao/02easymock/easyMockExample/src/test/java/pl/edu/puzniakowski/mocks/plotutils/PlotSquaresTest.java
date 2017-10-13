package pl.edu.puzniakowski.mocks.plotutils;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import static org.junit.Assert.*;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;

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
        verify(mockedPlotter).getPositionX();
        verify(mockedPlotter).getPositionY();
        verify(mockedPlotter).gotoXY(x0 - r, y0 - r);
        verify(mockedPlotter).gotoXY(x0 + r, y0 - r);
        verify(mockedPlotter).gotoXY(x0 + r, y0 + r);
        verify(mockedPlotter).gotoXY(x0 - r, y0 + r);
    }
}
