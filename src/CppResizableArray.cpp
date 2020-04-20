//============================================================================
// Name        : CppResizableArray.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <gtest/gtest.h>
#include "ResArray.h"
using namespace std;

TEST(Array_Test, canAddAndGetElements)
{
	ResArray<int> array;
	for(int i = 0; i < 5; i++)
	{
		array.add(i);
	}

	for(int i = 0; i < 5; i++)
	{
		ASSERT_EQ(i, array.get(i));
	}
}

TEST(Array_Test, canAddToAGivenIndex)
{
	ResArray<int> array;
	array.add(0,7);
	array.add(0,5);
	array.add(1,6);
	ASSERT_EQ(5, array.get(0));
	ASSERT_EQ(6, array.get(1));
	ASSERT_EQ(7, array.get(2));
}

TEST(Array_Test, AddingToNonExistingIndexThrowsException)
{
	ResArray<int> array;
	ASSERT_THROW(array.add(5,7), ArrayIndexOutOfBoundException);
}

TEST(Array_Test, AccessingNonExistingIndexThrowsException)
{
	ResArray<int> array;
	ASSERT_THROW(array.get(5), ArrayIndexOutOfBoundException);
}

TEST(Array_Test, canUpdateExistingElement)
{
	ResArray<int> array;
	array.add(5);
	array.add(6);
	array.update(0, 2);
	array.update(1, 3);
	ASSERT_EQ(2, array.get(0));
	ASSERT_EQ(3, array.get(1));
}

TEST(Array_Test, UpdatingNonExistingIndexThrowsException)
{
	ResArray<int> array;
	ASSERT_THROW(array.update(5,7), ArrayIndexOutOfBoundException);
}

TEST(Array_Test, canGetSize)
{
	ResArray<int> array;
	array.add(2);
	array.add(3);
	array.add(4);
	ASSERT_EQ((unsigned int)3, array.size());
}

TEST(Array_Test, canRemoveElementInSpecifiedIndex)
{
	ResArray<int> array;
	array.add(1);
	array.add(2);
	array.add(3);
	array.remove_element(1);
	ASSERT_EQ(3, array.get(1));
}

TEST(Array_Test, removingNonExistingIndexThrowsException)
{
	ResArray<int> array;
	ASSERT_THROW(array.remove_element(1), ArrayIndexOutOfBoundException);
}

TEST(Array_Test, canFindFirstOccurrenceOfAnElement)
{
	ResArray<int> array;
	array.add(1);
	array.add(2);
	array.add(1);
	array.remove_element(1);
	ASSERT_EQ(0, array.indexOf(1));
	ASSERT_EQ(-1, array.indexOf(3));
}

TEST(Array_Test, canFindTheExistanceOfAnElement)
{
	ResArray<int> array;
	array.add(1);
	array.add(2);
	array.add(1);
	array.remove_element(1);
	ASSERT_EQ(true, array.contains(1));
	ASSERT_EQ(false, array.contains(3));
}

TEST(Array_Test, canUseArrayIndexOperator)
{
	ResArray<int> array;
	array.add(5);
	ASSERT_EQ(5, array[0]);
	array[0] = 6;
	ASSERT_EQ(6, array[0]);

	ASSERT_THROW(array[2], ArrayIndexOutOfBoundException);
}
