/* 
 * File:   pokerdefs.h
 * Author: batman
 *
 * Created on February 19, 2014, 10:09 PM
 */

#ifndef POKERDEFS_H
#define	POKERDEFS_H

#include <decimal.h>

namespace Poker{
    using namespace dec;

    /*
     * Representation for all monetary
     * variables. 1 unit is one bigblind
     */
    typedef decimal<6> amt_bb;

    inline amt_bb amt_bb_cast(int amt){
        return decimal_cast<6>(amt);
    }

    inline amt_bb amt_bb_cast(double amt){
        return decimal_cast<6>(amt);
    }
}

#endif	/* POKERDEFS_H */

