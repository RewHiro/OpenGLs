#pragma once


namespace utility
{

/// <summary>
/// �R�s�[�֎~�N���X
/// </summary>
class Noncopyable
{
public:
	Noncopyable(Noncopyable&) = delete;
	Noncopyable operator= (Noncopyable&) = delete;
};

}