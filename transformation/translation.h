#pragma once

#include <geometrie/vecteur.h>
#include "transformation.h"
#include <formes/segment.h>
#include <formes/cercle.h>
#include <formes/triangle.h>
#include <formes/polygone.h>

class Translation : public Transformation {
    private:
        Vecteur _translation;

    public:
        /**
         * @brief Crée une opération de translation
         * @param translation Vecteur de translation
         */
        Translation(const Vecteur& translation);

        void modifier(Segment* segment) const override;
        void modifier(Cercle* cercle) const override;
        void modifier(Triangle* triangle) const override;

    protected:
        virtual Vecteur nouveauPointPolygone(const Vecteur& point) const override;
};