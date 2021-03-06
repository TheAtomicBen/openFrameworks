//
// SessionImpl.h
//
// $Id: //poco/1.4/Data/include/Poco/Data/SessionImpl.h#1 $
//
// Library: Data
// Package: DataCore
// Module:  SessionImpl
//
// Definition of the SessionImpl class.
//
// Copyright (c) 2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Data_SessionImpl_INCLUDED
#define Data_SessionImpl_INCLUDED


#include "Poco/Data/Data.h"
#include "Poco/RefCountedObject.h"
#include "Poco/Any.h"


namespace Poco {
namespace Data {


class StatementImpl;


class Data_API SessionImpl: public Poco::RefCountedObject
	/// Interface for Session functionality that subclasses must extend. 
	/// SessionImpl objects are noncopyable.
{
public:
	SessionImpl();
		/// Creates the SessionImpl.

	virtual ~SessionImpl();
		/// Destroys the SessionImpl.

	virtual StatementImpl* createStatementImpl() = 0;
		/// Creates a StatementImpl.

	virtual void begin() = 0;
		/// Starts a transaction.

	virtual void commit() = 0;
		/// Commits and ends a transaction.

	virtual void rollback() = 0;
		/// Aborts a transaction.
		
	virtual void close() = 0;
		/// Closes the connection.

	virtual bool isConnected() = 0;
		/// Returns true iff session is connected, false otherwise.

	virtual bool isTransaction() = 0;
		/// Returns true iff a transaction is a transaction is in progress, false otherwise.

	virtual void setFeature(const std::string& name, bool state) = 0;
		/// Set the state of a feature.
		///
		/// Features are a generic extension mechanism for session implementations.
		/// and are defined by the underlying SessionImpl instance.
		///
		/// Throws a NotSupportedException if the requested feature is
		/// not supported by the underlying implementation.
	
	virtual bool getFeature(const std::string& name) = 0;
		/// Look up the state of a feature.
		///
		/// Features are a generic extension mechanism for session implementations.
		/// and are defined by the underlying SessionImpl instance.
		///
		/// Throws a NotSupportedException if the requested feature is
		/// not supported by the underlying implementation.

	virtual void setProperty(const std::string& name, const Poco::Any& value) = 0;
		/// Set the value of a property.
		///
		/// Properties are a generic extension mechanism for session implementations.
		/// and are defined by the underlying SessionImpl instance.
		///
		/// Throws a NotSupportedException if the requested property is
		/// not supported by the underlying implementation.

	virtual Poco::Any getProperty(const std::string& name) = 0;
		/// Look up the value of a property.
		///
		/// Properties are a generic extension mechanism for session implementations.
		/// and are defined by the underlying SessionImpl instance.
		///
		/// Throws a NotSupportedException if the requested property is
		/// not supported by the underlying implementation.

private:
	SessionImpl(const SessionImpl&);
	SessionImpl& operator = (const SessionImpl&);
};


} } // namespace Poco::Data


#endif // Data_SessionImpl_INCLUDED
