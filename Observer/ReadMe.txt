=====================================================================
Description
=====================================================================
/*
* Observer is a behavioral design pattern that allows some 
* objects to notify other objects about changes in their state
*/
=====================================================================
Design Goal
=====================================================================
/*
*  1. Define an one to many dependency between objects so that
*     when one object changes state, all its dependents are 
*     notified and updated automatically.
*  2. Encapsulate the core (or common or engine) components in
*     a Subject abstraction, and the variable components in 
*     an Observer history.
*  3. The View part of Model-View-Controller.
*/
=====================================================================
Check list
=====================================================================
/*
*  1. Differentiate between the core (or independent) functionality
*     and the optional (or dependent) functionality.
*  2. Model the independent functionality with a Subject abstraction.
*  3. Model the dependenent functionality with an Observer hierarchy.
*  4. The Subject is coupled only to the Observer base class.
*  5. The client configures the number and type of Observers.
*  6. Observers register themselves with the Subject.
*  7. The Subject broadcasts events to all registered Observers.
*  8. The Subject may push information at the Observers,or, the Observers
*     may pull the information the need from the Subject.
*/