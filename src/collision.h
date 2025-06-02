#pragma once
#include "raylib.h"
#include "contact.h"
#include <vector>	

using bodies_t = std::vector<struct Body*>;
using springs_t = std::vector<struct Spring*>;
using contacts_t = std::vector<Contact>;


void CreateContacts(const bodies_t& bodies, contacts_t& contacts);
void SeparateContacts(contacts_t& contacts);
void ResolveContacts(contacts_t& contacts);
