#!/usr/bin/env python3

import sys
import h5py
import numpy as np

from example import AmiciExample, dict2attrs

class ExampleNestedEvents(AmiciExample):
  
    def __init__(self):
        AmiciExample.__init__( self )
        
        self.numX = 1
        self.numP = 5
        self.numK = 0
        self.numZ = 1
        
        self.modelOptions['theta'] = np.log10([0.1, 1000, 2, 8e-1, 1.6])
        self.modelOptions['ts'] = np.linspace(0, 20, 100)
        self.modelOptions['pscale'] = 2
        self.modelOptions['qpositivex'] = [0] * self.numX 
    
        self.solverOptions['atol'] = 1e-12
        self.solverOptions['maxsteps'] = 1e4
        self.solverOptions['nmaxevent'] = 2
        self.solverOptions['rtol'] = 1e-14
        self.solverOptions['sens_ind'] = []
        self.solverOptions['sensi'] = 0
        self.solverOptions['sensi_meth'] = 1

        self.data['Y'] = [np.nan] * len(self.modelOptions['ts'])
        self.data['Sigma_Y'] = [np.nan] * len(self.modelOptions['ts'])
        self.data['Sigma_Z'] = [np.array(np.full((self.numZ, self.solverOptions['nmaxevent']), 0.5))]
        self.data['Z'] = [np.array(np.full((self.numZ, 2), np.nan))]
        self.data['condition'] = self.modelOptions['kappa']
        self.data['t'] = self.modelOptions['ts']
    

def writeNoSensi(filename):
    ex = ExampleNestedEvents()

    ex.writeToFile(filename, '/model_nested_events/nosensi/')


def writeSensiForward(filename):
    ex = ExampleNestedEvents()

    ex.solverOptions['sens_ind'] = np.arange(0, ex.numP) + 1
    ex.solverOptions['pbar'] = [1.0] * len(ex.solverOptions['sens_ind'])
    ex.solverOptions['sensi'] = 1

    ex.writeToFile(filename, '/model_nested_events/sensiforward/')


def main():
    if len(sys.argv) < 2:
        print("Error: Must provide output file as first and only argument.")
        sys.exit(1)
    filename = sys.argv[1]

    writeNoSensi(filename)
    writeSensiForward(filename)
    
if __name__ == "__main__":
    main()
    