package pl.edu.puzniakowski.mocks.plotutils;
//import static org.mockito.Mockito.*;
import org.mockito.Mock;
import org.mockito.Mockito;
import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;
import pl.edu.puzniakowski.mocks.plotters.PlotterDriver;

public class PlotSquaresTest {
    PlotSquares plotSquares = new PlotSquares();

    @Mock
    PlotterDriver mockedPlotter;

    @Before
    public  void setup() {
        plotSquares.setPlotterDriver(mockedPlotter);
    }

    @Test
    public  void testDrawSquares() {
        plotSquares.drawSquareInPlace(5);
    }
}
