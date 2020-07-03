/**
 *
 *  @file ProjectComponent.cpp
 *  @authors David Berres, Nico Schorr
 *  @date 03.07.2020
 */

#include "ProjectComponent.h"

ProjectComponent::ProjectComponent(const std::string& name, const std::string& description)
    : name(name), description(description) {
    uniqueId = ProjectComponent::uniqueIDCounter++;
}
