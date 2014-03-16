/* 
 * File:   LineIntegralConvolution.h
 * Author: stup
 *
 * Created on August 12, 2013, 11:39 PM
 */

#ifndef LINEINTEGRALCONVOLUTION_H
#define	LINEINTEGRALCONVOLUTION_H

#include "F.h"

class LicStreamline{
    public:
        LicStreamline();
        ~LicStreamline();
        int size();
        void setSeed(int cell);
        void addForwardCell(int cell);
        void addBackwardCell(int cell);
        void clear();
        
        int& operator[](int m);
        
        
    private:
        std::vector<int> streamBackward_;
        std::vector<int> streamForward_;
        int seedCell_;
};

class LineIntegralConvolution : public F{

public:
	LineIntegralConvolution();
	~LineIntegralConvolution();
	bool execute();
        bool updateOptions();
        
        
        
private:
        //Streamline
        double dt_;  
        double minHits_;
        int m_;
        
        //Convolution
        int convolutionLength_;
        
        //Noise texture
        std::vector<double> texture_;
        
        //LIC
        std::vector<int> numHits_;
        std::vector<double> pixelIntensity_;
        
        //Streamline
        LicStreamline streamline;
        
        void generateInputTexture();
        void computeStreamline(int cell);
        void computeConvolution();
        int interpolateEuler(double *p, double dt);
        
};

#endif	/* LINEINTEGRALCONVOLUTION_H */

