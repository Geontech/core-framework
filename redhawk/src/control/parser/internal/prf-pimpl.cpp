/*
 * This file is protected by Copyright. Please refer to the COPYRIGHT file
 * distributed with this source distribution.
 *
 * This file is part of REDHAWK core.
 *
 * REDHAWK core is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * REDHAWK core is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */
// Not copyrighted - public domain.
//
// This sample parser implementation was generated by CodeSynthesis XSD,
// an XML Schema to C++ data binding compiler. You may use it in your
// programs without any restrictions.
//
#include<iterator>
#include "prf-pimpl.h"
#include "ossie/debug.h"

// Unit_pimpl
//

using namespace prf;

CREATE_LOGGER(prf_parser)

rh_logger::LoggerPtr prf::parserLog;

void Unit_pimpl::
pre ()
{
}

std::string Unit_pimpl::
post_Unit ()
{
  const ::std::string& v (post_string ());

  return v;
}

// AccessType_pimpl
//

void AccessType_pimpl::
pre ()
{
}

::ossie::Property::AccessType AccessType_pimpl::
post_AccessType ()
{
    const std::string& mode = post_string();
    if (mode == "readwrite") {
        return ossie::Property::MODE_READWRITE;
    } else if (mode == "readonly") {
        return ossie::Property::MODE_READONLY;
    } else if (mode == "writeonly") {
        return ossie::Property::MODE_WRITEONLY;
    } else {
        RH_WARN(prf::parserLog, "Invalid mode '" << mode << "'");
        return ossie::Property::MODE_DEFAULT;
    }
}

// IsComplex_pimpl
//

void IsComplex_pimpl::
pre ()
{
}

bool IsComplex_pimpl::
post_IsComplex ()
{
  return post_string() == "true";
}

// IsCommandLine_pimpl
//

void IsCommandLine_pimpl::
pre ()
{
}

bool IsCommandLine_pimpl::
post_IsCommandLine ()
{
  return post_string() == "true";
}

// IsOptional_pimpl
//

void IsOptional_pimpl::
pre ()
{
}

bool IsOptional_pimpl::
post_IsOptional ()
{
  return post_string() == "true";
}

// action_pimpl
//

void action_pimpl::
pre ()
{
}

void action_pimpl::
type (ossie::Property::ActionType type)
{
    _type = type;
}

ossie::Property::ActionType action_pimpl::
post_action ()
{
  return _type;
}

// ActionType_pimpl
//

void ActionType_pimpl::
pre ()
{
}

ossie::Property::ActionType ActionType_pimpl::
post_ActionType ()
{
    const std::string& action = post_string();
    if (action == "ge") {
        return ossie::Property::ACTION_GE;
    } else if (action == "gt") {
        return ossie::Property::ACTION_GT;
    } else if (action == "le") {
        return ossie::Property::ACTION_LE;
    } else if (action == "lt") {
        return ossie::Property::ACTION_LT;
    } else if (action == "ne") {
        return ossie::Property::ACTION_NE;
    } else if (action == "eq") {
        return ossie::Property::ACTION_EQ;
    } else if (action == "external") {
        return ossie::Property::ACTION_EXTERNAL;
    } else {
        RH_WARN(prf::parserLog, "Invalid action '" << action << "'");
        return ossie::Property::ACTION_DEFAULT;
    }
}

// configurationKind_pimpl
//

void configurationKind_pimpl::
pre ()
{
    _kindtype = ossie::Property::KIND_DEFAULT;
}

void configurationKind_pimpl::
kindtype (ossie::Property::KindType kindtype)
{
    _kindtype = kindtype;
}

ossie::Property::KindType configurationKind_pimpl::
post_configurationKind ()
{
    return _kindtype;
}

// enumeration_pimpl
//

void enumeration_pimpl::
pre ()
{
}

void enumeration_pimpl::
label (const ::std::string& label)
{
}

void enumeration_pimpl::
value (const ::std::string& value)
{
}

::std::map<std::string, std::string>::value_type enumeration_pimpl::
post_enumeration ()
{
    return std::map<std::string, std::string>::value_type("", "");
}

// enumerations_pimpl
//

void enumerations_pimpl::
pre ()
{
}

void enumerations_pimpl::
enumeration (const ::std::map<std::string, std::string>::value_type& enumeration)
{
}

::std::map<std::string, std::string> enumerations_pimpl::
post_enumerations ()
{
    return std::map<std::string, std::string>();
}

// inputValue_pimpl
//

void inputValue_pimpl::
pre ()
{
}

void inputValue_pimpl::
simple (const ossie::Property* simple)
{
}

void inputValue_pimpl::
post_inputValue ()
{
}

// kind_pimpl
//

void kind_pimpl::
pre ()
{
    _type = ossie::Property::KIND_DEFAULT;
}

void kind_pimpl::
kindtype (ossie::Property::KindType type)
{
    _type = type;
}

ossie::Property::KindType kind_pimpl::
post_kind ()
{
    return _type;
}

// PropertyConfigurationType_pimpl
//

void PropertyConfigurationType_pimpl::
pre ()
{
}

ossie::Property::KindType PropertyConfigurationType_pimpl::
post_PropertyConfigurationType ()
{
    const std::string& kindtype = post_string();
    RH_TRACE(prf::parserLog, "PropertyConfigurationType = " << kindtype);
    if (kindtype == "configure") {
        return ossie::Property::KIND_CONFIGURE;
    } else if (kindtype == "execparam") {
        return ossie::Property::KIND_EXECPARAM;
    } else if (kindtype == "allocation") {
        return ossie::Property::KIND_ALLOCATION;
    } else if (kindtype == "factoryparam") {
        return ossie::Property::KIND_FACTORYPARAM;
    } else if (kindtype == "test") {
        return ossie::Property::KIND_TEST;
    } else if (kindtype == "event") {
        return ossie::Property::KIND_EVENT;
    } else if (kindtype == "message") {
        return ossie::Property::KIND_MESSAGE;
    } else if (kindtype == "property") {
        return ossie::Property::KIND_PROPERTY;
    } else {
        // The generated part of the parser does not validate that the value is
        // in the allowed range; just to be safe, treat it as the default
        return ossie::Property::KIND_DEFAULT;
    }
}

// StructPropertyConfigurationType_pimpl
//

void StructPropertyConfigurationType_pimpl::
pre ()
{
}

ossie::Property::KindType StructPropertyConfigurationType_pimpl::
post_StructPropertyConfigurationType ()
{
    ossie::Property::KindType kind = post_PropertyConfigurationType();
    if (kind == ossie::Property::KIND_EXECPARAM) {
        RH_WARN(prf::parserLog, "Struct properties cannot have kind 'execparam'");
    }
    return kind;
}

// properties_pimpl
//

void properties_pimpl::
pre ()
{
    this->_prf.reset(new ossie::PRF());
}

void properties_pimpl::
description (const ::std::string& description)
{
}

void properties_pimpl::
simple (ossie::SimpleProperty* simple)
{
    RH_TRACE(prf::parserLog, "Adding simple property " << simple->getID())
    assert(_prf.get() != 0);
    _prf->addProperty(simple);
}

void properties_pimpl::
simplesequence (ossie::SimpleSequenceProperty* simplesequence)
{
  RH_TRACE(prf::parserLog, "Adding simple sequence property " << simplesequence->getID());
  assert(_prf.get() != 0);
  _prf->addProperty(simplesequence);
}

void properties_pimpl::
test ()
{
}

void properties_pimpl::
struct_ (ossie::StructProperty* struct_)
{
  RH_TRACE(prf::parserLog, "Adding struct property " << struct_->getID());
  assert(_prf.get() != 0);
  _prf->addProperty(struct_);
}

void properties_pimpl::
structsequence (ossie::StructSequenceProperty* structsequence)
{
  RH_TRACE(prf::parserLog, "Adding struct sequence property " << structsequence->getID());
  assert(_prf.get() != 0);
  _prf->addProperty(structsequence);
}

std::auto_ptr<ossie::PRF> properties_pimpl::
post_properties ()
{
    RH_TRACE(prf::parserLog, "properties post")
    return _prf;
}

// PropertyValueType_pimpl
//

void PropertyValueType_pimpl::
pre ()
{
}

std::string PropertyValueType_pimpl::
post_PropertyValueType ()
{
  const ::std::string& v (post_string ());

  return v;
}

// range_pimpl
//

void range_pimpl::
pre ()
{
}

void range_pimpl::
max (const ::std::string& max)
{
    range.second = max;
}

void range_pimpl::
min (const ::std::string& min)
{
    range.first = min;
}

::std::pair<std::string, std::string> range_pimpl::
post_range ()
{
    return range;
}

// resultValue_pimpl
//

void resultValue_pimpl::
pre ()
{
}

void resultValue_pimpl::
simple (const ossie::Property* simple)
{
}

void resultValue_pimpl::
post_resultValue ()
{
}

// simple_pimpl
//

void simple_pimpl::
pre ()
{
    _id.clear();
    _name.clear();
    _type.clear();
    _mode = ossie::Property::MODE_DEFAULT;
    _action = ossie::Property::ACTION_DEFAULT;
    _kinds = ossie::Property::Kinds();
    _complex = false;
    _optional = false;
    _commandline = false;
    _value.reset();

}

void simple_pimpl::
description (const ::std::string& description)
{
  
}

void simple_pimpl::
value (const ::std::string& value)
{
    RH_TRACE(prf::parserLog, "simple_pimpl value " << value)
    _value = std::auto_ptr<std::string>(new std::string(value));
}

void simple_pimpl::
units ()
{
}

void simple_pimpl::
range (const ::std::vector<std::string>& range)
{
}

void simple_pimpl::
enumerations (const ::std::map<std::string, std::string>& enumerations)
{
}

void simple_pimpl::
kind (ossie::Property::KindType kind)
{
    RH_TRACE(prf::parserLog, "simple_pimpl kind " << kind)
    _kinds |= kind;
}

void simple_pimpl::
action (ossie::Property::ActionType action)
{
    RH_TRACE(prf::parserLog, "simple_pimpl action " << action)
    _action = action;
}

void simple_pimpl::
id (const ::std::string& id)
{
    RH_TRACE(prf::parserLog, "simple_pimpl id " << id)
    _id = id;
}

void simple_pimpl::
mode (ossie::Property::AccessType mode)
{
    RH_TRACE(prf::parserLog, "simple_pimpl mode " << mode)
    _mode = mode;
}

void simple_pimpl::
name (const ::std::string& name)
{
    RH_TRACE(prf::parserLog, "simple_pimpl name " << name)
    _name = name;
}

void simple_pimpl::
type (const ::std::string& type)
{
    RH_TRACE(prf::parserLog, "simple_pimpl type " << type)
    _type = type;
}

void simple_pimpl::
complex (bool complex)
{
    RH_TRACE(prf::parserLog, "simple_pimpl complex " << complex)
    _complex = complex;
}

void simple_pimpl::
optional (bool optional)
{
    RH_TRACE(prf::parserLog, "simple_pimpl optional " << optional)
    _optional = optional;
}

void simple_pimpl::
commandline (bool commandline)
{
    RH_TRACE(prf::parserLog, "simple_pimpl commandline " << commandline)
    _commandline = commandline;
}

ossie::SimpleProperty* simple_pimpl::
post_simple ()
{
  if (_value.get()) {
      RH_TRACE(prf::parserLog, "simple_pimpl post " << _id << " " << _name << " " << _kinds << " " << *_value);
  } else {
      RH_TRACE(prf::parserLog, "simple_pimpl post " << _id << " " << _name << " " << _kinds << " None");
  }
  return new ossie::SimpleProperty(_id, _name, _type, _mode, _action, _kinds, _value.get(), _complex, _commandline, _optional);
}

// simpleRef_pimpl
//

void simpleRef_pimpl::
pre ()
{
  simple =  ossie::SimplePropertyRef();
}

void simpleRef_pimpl::
refid (const ::std::string& refid)
{
    simple._id = refid;
}

void simpleRef_pimpl::
value (const ::std::string& value)
{
    simple._value = value;
}

const ossie::SimplePropertyRef& simpleRef_pimpl::
post_simpleRef ()
{
    return simple;
}

// simpleSequenceRef_pimpl
//

void simpleSequenceRef_pimpl::
pre ()
{
  simplesequence._values.clear();
  simplesequence = ossie::SimpleSequencePropertyRef();
}

void simpleSequenceRef_pimpl::
refid (const ::std::string& refid)
{
    simplesequence._id = refid;
}

void simpleSequenceRef_pimpl::
values (const ::std::vector<std::string>& values)
{
  simplesequence._values = values;
}

const ossie::SimpleSequencePropertyRef& simpleSequenceRef_pimpl::
post_simpleSequenceRef ()
{
    return simplesequence;
}

// simpleSequence_pimpl
//

void simpleSequence_pimpl::
pre ()
{
    _id.clear();
    _name.clear();
    _type.clear();
    _mode = ossie::Property::MODE_DEFAULT;
    _action = ossie::Property::ACTION_DEFAULT;
    _kinds = ossie::Property::Kinds();
    _complex = false;
    _optional = false;
    _values.clear();
}

void simpleSequence_pimpl::
description (const ::std::string& description)
{
}

void simpleSequence_pimpl::
values (const ::std::vector<std::string>& values)
{
    std::string vals;
    for (unsigned i=0; i<values.size(); ++i) {
        vals += values[i] + " ";
    }
    RH_TRACE(prf::parserLog, "simpleSequence_pimpl values " << vals);
    _values = values;
}

void simpleSequence_pimpl::
units ()
{
}

void simpleSequence_pimpl::
range (const ::std::vector<std::string>& range)
{
}

void simpleSequence_pimpl::
kind (ossie::Property::KindType kind)
{
    RH_TRACE(prf::parserLog, "simpleSequence_pimpl kind " << kind)
    _kinds |= kind;
}

void simpleSequence_pimpl::
action (ossie::Property::ActionType action)
{
    RH_TRACE(prf::parserLog, "simpleSequence_pimpl action " << action)
    _action = action;
}

void simpleSequence_pimpl::
id (const ::std::string& id)
{
    RH_TRACE(prf::parserLog, "simpleSequence_pimpl id " << id)
    _id = id;
}

void simpleSequence_pimpl::
mode (ossie::Property::AccessType mode)
{
    RH_TRACE(prf::parserLog, "simple_pimpl mode " << mode)
    _mode = mode;
}

void simpleSequence_pimpl::
name (const ::std::string& name)
{
    RH_TRACE(prf::parserLog, "simpleSequence_pimpl name " << name)
    _name = name;
}

void simpleSequence_pimpl::
type (const ::std::string& type)
{
    RH_TRACE(prf::parserLog, "simpleSequence_pimpl type " << type)
    _type = type;
}

void simpleSequence_pimpl::
complex (bool complex)
{
    RH_TRACE(prf::parserLog, "simpleSequence_pimpl complex " << complex)
    _complex = complex;
}

void simpleSequence_pimpl::
optional (bool optional)
{
    RH_TRACE(prf::parserLog, "simpleSequence_pimpl optional " << optional)
    _optional = optional;
}

ossie::SimpleSequenceProperty* simpleSequence_pimpl::
post_simpleSequence ()
{
  return new ossie::SimpleSequenceProperty(_id, 
                                           _name, 
                                           _type, 
                                           _mode, 
                                           _action, 
                                           _kinds, 
                                           _values,
                                           _complex,
                                           _optional);
}

// struct_pimpl
//

void struct_pimpl::
pre ()
{

    _id.clear();
    _name.clear();
    _mode = ossie::Property::MODE_DEFAULT;
    _kinds = ossie::Property::Kinds();
    _value.clear();
}

void struct_pimpl::
description (const ::std::string& desciption)
{
}

void struct_pimpl::
simple (ossie::SimpleProperty* property)
{
   _value.push_back(property);
}

void struct_pimpl::
simplesequence (ossie::SimpleSequenceProperty* property)
{
    _value.push_back(property);
}

void struct_pimpl::
configurationkind (ossie::Property::KindType kind)
{
    _kinds |= kind;
}

void struct_pimpl::
id (const ::std::string& id)
{
    _id = id;
}

void struct_pimpl::
mode (ossie::Property::AccessType mode)
{
    _mode = mode;
}

void struct_pimpl::
name (const ::std::string& name)
{
    _name = name;
}

ossie::StructProperty* struct_pimpl::
post_struct ()
{
    RH_TRACE(prf::parserLog, "struct_pimpl post " << _id << " " << _name << " kinds " << _kinds);
    
    ossie::PropertyList::const_iterator i;
    for (i = _value.begin(); i != _value.end(); ++i) {
        RH_TRACE(prf::parserLog, "    value " << *i)
    }

    return new ossie::StructProperty(_id, _name, _mode, _kinds, _value);
}

// structSequence_pimpl
//

void structSequence_pimpl::
pre ()
{
    _id.clear();
    _name.clear();
    _mode = ossie::Property::MODE_DEFAULT;
    _kinds = ossie::Property::Kinds();
    _values.clear();
    _struct.reset();  // resets internal values vector
}

void structSequence_pimpl::
description (const ::std::string& description)
{
}

void structSequence_pimpl::
struct_ (ossie::StructProperty* structProp)
{
    _struct.reset(structProp);
}

void structSequence_pimpl::
structvalue (const ossie::ComponentPropertyMap& value)
{
    assert(_struct.get() != 0);
    ossie::PropertyList propValue;
    const ossie::PropertyList& defaults = _struct->getValue();
    for (ossie::PropertyList::const_iterator prop = defaults.begin(); prop != defaults.end(); ++prop) {
        const std::string id = prop->getID();
        ossie::ComponentPropertyMap::const_iterator ii = value.find(id);
        if (ii != value.end()) {
            ossie::Property* field = prop->clone();
            propValue.push_back(field);
            field->override(ii->second);
	}
    }
    _values.push_back(ossie::StructProperty(_struct->getID(), _struct->getName(), _struct->getMode(), _struct->getKinds(), propValue));
}

void structSequence_pimpl::
configurationkind (ossie::Property::KindType kind)
{
    _kinds |= kind;
}

void structSequence_pimpl::
id (const ::std::string& id)
{
    _id = id;
}

void structSequence_pimpl::
mode (ossie::Property::AccessType mode)
{
    _mode = mode;
}

void structSequence_pimpl::
name (const ::std::string& name)
{
    _name = name;
}

ossie::StructSequenceProperty* structSequence_pimpl::
post_structSequence ()
{
    return new ossie::StructSequenceProperty(_id, _name, _mode, *_struct, _kinds, _values);
}

// structValue_pimpl
//

void structValue_pimpl::
pre ()
{
  _values.clear();
}

void structValue_pimpl::
simpleref (const ossie::SimplePropertyRef& simpleref)
{
  _values.insert(simpleref._id,std::auto_ptr<ossie::ComponentProperty>(simpleref.clone()) );
}

void structValue_pimpl::
simplesequenceref (const ossie::SimpleSequencePropertyRef& simplesequenceref)
{
  _values.insert(simplesequenceref._id,std::auto_ptr<ossie::ComponentProperty>(simplesequenceref.clone()) );
}

const ossie::ComponentPropertyMap& structValue_pimpl::
post_structValue ()
{
  return _values;
}

// test_pimpl
//

void test_pimpl::
pre ()
{
}

void test_pimpl::
description (const ::std::string& description)
{
}

void test_pimpl::
inputvalue ()
{
}

void test_pimpl::
resultvalue ()
{
}

void test_pimpl::
id (const ::std::string& id)
{
}

void test_pimpl::
post_test ()
{
}

// values_pimpl
//

void values_pimpl::
pre ()
{
    values.clear();
}

void values_pimpl::
value (const ::std::string& value)
{
    values.push_back(value);
}

::std::vector<std::string> values_pimpl::
post_values ()
{
  return values;
}
