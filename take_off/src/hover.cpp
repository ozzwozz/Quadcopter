#include "include/hover.hpp"

int hover::VerticalControl(int[3] currentPos)
{
    int Z_target = sp[2];
    int z_Current;
    
    targetPos=sim.getObjectPosition(targetObj,-1)
    pos=sim.getObjectPosition(d,-1)
    l=sim.getVelocity(heli)
    e=(targetPos[3]-pos[3])
    cumul=cumul+e
    pv=pParam*e
    thrust=5.45+pv+iParam*cumul+dParam*(e-lastE)+l[3]*vParam
    lastE=e
    return z;
}
int[2] hover::HorizontalControl(int[3] sp)
{
    int x, y;
    m=sim.getObjectMatrix(d,-1)
    vx={1,0,0};
    vx=sim.multiplyVector(m,vx)
    vy={0,1,0};
    vy=sim.multiplyVector(m,vy)
    alphaE=(vy[3]-m[12])
    alphaCorr=0.25*alphaE+2.1*(alphaE-pAlphaE)
    betaE=(vx[3]-m[12])
    betaCorr=-0.25*betaE-2.1*(betaE-pBetaE)
    static pAlphaE=alphaE
    static pBetaE=betaE
    alphaCorr=alphaCorr+sp[2]*0.005+1*(sp[2]-psp2)
    betaCorr=betaCorr-sp[1]*0.005-1*(sp[1]-psp1)
    static psp2=sp[2]
    static psp1=sp[1]

    return var[x, y];
}

// Controls the direction in which the drone is pointing
void hover::Rotational_Control(int[3] currentEuler)
{
    int rotCorr[2];
    for (i = 0; i < 2; i++)
    {
      rotCorr[i] = currentEuler[i] - TargetEuler[i];
      rotCorr[i] = currentEuler[i] - TargetEuler[i];
      rotCorr[i] = currentEuler[i] - TargetEuler[i];
    }
    return rotCorr;
}

void hover::Move_Pub_()
{
    // Decide of the motor velocities;
    handlePropeller(1,thrust*(1-alphaCorr+betaCorr+rotCorr));
    handlePropeller(2,thrust*(1-alphaCorr-betaCorr-rotCorr));
    handlePropeller(3,thrust*(1+alphaCorr-betaCorr+rotCorr));
    handlePropeller(4,thrust*(1+alphaCorr+betaCorr-rotCorr));
    drone_twist.linear.x = ;
    drone_twist.linear.y = ;
    drone_twist.linear.z = ;
    publisher_->publish();
}
