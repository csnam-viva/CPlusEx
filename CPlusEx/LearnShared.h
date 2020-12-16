#pragma once
#include <string>
typedef std::basic_string<TCHAR> tstring;

struct MediaAsset
{
    virtual ~MediaAsset() = default; // make it polymorphic
};

struct Song : public MediaAsset
{
    tstring artist;
    tstring title;
    Song(const tstring& artist_, const tstring& title_) :
        artist{ artist_ }, title{ title_ } {}
};

struct Photo : public MediaAsset
{
    tstring date;
    tstring location;
    tstring subject;
    Photo(
        const tstring& date_,
        const tstring& location_,
        const tstring& subject_) :
        date{ date_ }, location{ location_ }, subject{ subject_ } {}
};


class LearnShared
{


};

