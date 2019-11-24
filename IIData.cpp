#include "IIData.hpp"

IIData::IIData()
{
}

IIData::IIData(const std::string &word)
{

    this->word = word;
}

std::string &IIData::getWord()
{

    return word;
}

std::vector<std::pair<std::string, std::vector<int> > > &IIData::getOccurrences()
{

    return occurrences;
}

void IIData::setWord(const std::string &word)
{

    this->word = word;
}

void IIData::setOccurrences(const std::vector<std::pair<std::string, std::vector<int> > > &occurrences)
{

    this->occurrences = occurrences;
}

void IIData::addOccurrence(const std::string &documentName, int position)
{
    /* TODO */
    std::vector<std::pair<std::string, std::vector<int> > > list = this->getOccurrences();
    std::cout << word <<" at: "<<documentName<<" "<<position<< " ii data lenth: "<<list.size()<<std::endl;

    

    for(int i = 0; i < list.size(); i++){
        std::cout<<"document name: "<< list.at(i).first<< std::endl;
        if(list.at(i).first == documentName){

            std::cout<<"--------------------"<<std::endl;

            std::vector<int> newVector;
            newVector.push_back(position);

            list.at(i).second.push_back(position);
            setOccurrences(list);
            return;
        }
    }
    std::vector<int> newVector;
    newVector.push_back(position);
    occurrences.push_back(std::make_pair(documentName, newVector));
    std::cout<<"added document name : " <<occurrences.at(0).first<<std::endl;
}

void IIData::removeOccurrences(const std::string &documentName)
{
    /* TODO */
}

bool IIData::operator<(const IIData &rhs) const
{

    return word < rhs.word;
}

bool IIData::operator>(const IIData &rhs) const
{

    return word > rhs.word;
}

bool IIData::operator==(const IIData &rhs) const
{

    return word == rhs.word;
}

std::ostream &operator<<(std::ostream &os, const IIData &data)
{

    os << "{";
    os << "word: " << data.word << ", ";
    os << "occurrences: [";
    for (unsigned int i = 0; i < data.occurrences.size(); ++i)
    {
        os << "(";
        os << data.occurrences[i].first << ", ";
        os << "[";
        if (!data.occurrences[i].second.empty())
        {
            for (unsigned int j = 0; j < data.occurrences[i].second.size() - 1; ++j)
            {
                os << data.occurrences[i].second[j] << ", ";
            }
            os << data.occurrences[i].second[data.occurrences[i].second.size() - 1];
        }
        os << "]";
        os << ")";
        if (i != data.occurrences.size() - 1)
        {
            os << ", ";
        }
    }
    os << "]";
    os << "}";

    return os;
}
