// https://sourcemaking.com/design_patterns/facade/cpp/1
// https://refactoring.guru/design-patterns/facade
// Facade is a structural design pattern that provides a simplified interface to a library, a framework, or any other complex set of classes.

#pragma once

#include <iostream>

using namespace std;

class MisDepartment
{
  public:
    void submitNetworkRequest()
    {
        m_state = 0;
    }
    bool checkOnStatus()
    {
        m_state++;
        if (m_state == Complete)
          return 1;
        return 0;
    }
  private:
    enum States
    {
        Received,
    	DenyAllKnowledge,
    	ReferClientToFacilities,
        FacilitiesHasNotSentPaperwork,
    	ElectricianIsNotDone,
    	ElectricianDidItWrong,
    	DispatchTechnician,
    	SignedOff,
    	DoesNotWork,
        FixElectriciansWiring,
    	Complete
    };
    int m_state;
};

class ElectricianUnion
{
  public:
    void submitNetworkRequest()
    {
        m_state = 0;
    }
    bool checkOnStatus()
    {
        m_state++;
        if (m_state == Complete)
          return 1;
        return 0;
    }
  private:
    enum States
    {
        Received,
    	RejectTheForm,
    	SizeTheJob,
    	SmokeAndJokeBreak,
    	WaitForAuthorization,
    	DoTheWrongJob,
    	BlameTheEngineer,
    	WaitToPunchOut,
    	DoHalfAJob,
    	ComplainToEngineer,
    	GetClarification,
    	CompleteTheJob,
    	TurnInThePaperwork,
    	Complete
    };
    int m_state;
};

class FacilitiesDepartment
{
  public:
    void submitNetworkRequest()
    {
        m_state = 0;
    }
    bool checkOnStatus()
    {
        m_state++;
        if (m_state == Complete)
          return 1;
        return 0;
    }
  private:
    enum States
    {
        Received,
    	AssignToEngineer,
    	EngineerResearches,
    	RequestIsNotPossible,
    	EngineerLeavesCompany,
    	AssignToNewEngineer,
    	NewEngineerResearches,
    	ReassignEngineer,
    	EngineerReturns,
    	EngineerResearchesAgain,
    	EngineerFillsOutPaperWork,
    	Complete
    };
    int m_state;
};

class FacilitiesFacade
{
  public:
    FacilitiesFacade() : m_count(0) {}

	void submitNetworkRequest()
    {
        m_state = 0;
    }

    bool checkOnStatus()
    {
        m_count++;
        /* Job request has just been received */
        if (m_state == Received)
        {
            m_state++;
            /* Forward the job request to the engineer */
            m_engineer.submitNetworkRequest();
            cout << "submitted to Facilities - " << m_count << " phone calls so far" << endl;
        }
        else if (m_state == SubmitToEngineer)
        {
            /* If engineer is complete, forward to electrician */
            if (m_engineer.checkOnStatus())
            {
                m_state++;
                m_electrician.submitNetworkRequest();
                cout << "submitted to Electrician - " << m_count << " phone calls so far" << endl;
            }
        }
        else if (m_state == SubmitToElectrician)
        {
            /* If electrician is complete, forward to technician */
            if (m_electrician.checkOnStatus())
            {
                m_state++;
                m_technician.submitNetworkRequest();
                cout << "submitted to MIS - " << m_count << " phone calls so far" << endl;
            }
        }
        else if (m_state == SubmitToTechnician)
        {
            /* If technician is complete, job is done */
            if (m_technician.checkOnStatus())
              return 1;
        }
        /* The job is not entirely complete */
        return 0;
    }
    int getNumberOfCalls() const
    {
        return m_count;
    }

private:
    enum States
    {
        Received,
    	SubmitToEngineer,
    	SubmitToElectrician,
    	SubmitToTechnician
    };

    int m_state;
    int m_count;
    FacilitiesDepartment m_engineer;
    ElectricianUnion m_electrician;
    MisDepartment m_technician;
};
